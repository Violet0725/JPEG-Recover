# cs50projects
Recover is a program that recovers JPEGs from a forensic image, per the below.
_**$ ./recover card.raw**_

Even though JPEGs are more complicated than BMPs, JPEGs have “signatures,” patterns of bytes that can distinguish them from other file formats. Specifically, the first three bytes of JPEGs are
_**0xff 0xd8 0xff**_
from the first byte to the third byte, left to right. The fourth byte, meanwhile, is either _**0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, or 0xef**_. 

This program iterates over a copy of a memory card, looking for JPEG signatures. Each time it finds a signature, it opens a new file for writing and starts filling that file with bytes from the memory card,
closing that file only once it encounters another signature.
