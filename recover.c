#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check if user entered correct file name
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int count = 0;
    BYTE buffer[512];
    FILE *output_file = NULL;
    char *filename = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(BYTE), 512, input_file))
    {

        //if is jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            //closing output file if it's not the first one
            if (count != 0)
            {
                fclose(output_file);
            }

            //make file name
            sprintf(filename, "%03i.jpg", count);

            //make file
            output_file = fopen(filename, "w");

            count++;


        }

        //if the output file is initialized
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(BYTE),512, output_file);
        }
    }

    free(filename);
    fclose(input_file);
    fclose(output_file);


    return 0;
}