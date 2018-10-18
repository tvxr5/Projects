#include <stdio.h>
#include <stdlib.h>

main()
{
	int	j;
	union {
		double	f;
		unsigned long long int	i;
		unsigned char	c[8];
	}	x;

/*
	printf ("Double : %d\n", sizeof (double));
	x.c[0] = 0x7f; x.c[1] = 0xef;
	x.c[2] = x.c[3] = x.c[4] = x.c[5] = x.c[6] = x.c[7] = 0xff;
	printf ("%75.70lE\n\n", x.f);
*/
	while (1) {
		scanf (" %lf", &(x.f));
		if (feof (stdin)) exit (0);
/*		printf ("%08x (%d) -- ", x.i, x.i); */
		printf ("%02x %02x %02x %02x %02x %02x %02x %02x\n", 
						x.c[0], x.c[1], x.c[2], x.c[3], x.c[4], 
						x.c[5], x.c[6], x.c[7]);
		for (j = 0; j < 8*sizeof (long long int); j ++) {
			printf ("%c", ((x.i & 0x8000000000000000LL) != 0) ? '1' : '0');
			x.i <<= 1;
			if (j == 0 || j == 11) printf (" ");
			}
		printf ("\n");
	}
}
