#include <stdio.h>
typedef union { int	i; unsigned char	b[4]; } MyU;

int main (int argc, char *argv[])
{
	MyU	x;

	x.i = 0x12345678;
	printf ("%02x %02x %02x %02x\n", x.b[0], x.b[1], x.b[2], x.b[3]);
	if (x.b[0] == 0x12)
		printf ("Big-Endian!\n");
	else
		printf ("Little-Endian!\n");
}
