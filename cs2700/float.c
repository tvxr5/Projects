#include <stdio.h>

main()
{
	int	j;
	union {
		float	f;
		unsigned int	i;
		unsigned char	c[4];
	}	x;

	while (1) {
		scanf (" %f", &(x.f));
		if (feof (stdin)) exit (0);
/*		printf ("%08x (%d) -- ", x.i, x.i);
		printf ("%02x %02x %02x %02x\n", x.c[0], x.c[1], x.c[2], x.c[3]); */
		for (j = 0; j < 8*sizeof (int); j ++) {
			printf ("%c", ((x.i & 0x80000000) != 0) ? '1' : '0');
			x.i <<= 1;
			if (j == 0 || j == 8) printf (" ");
			}
		printf ("\n");
	}
}
