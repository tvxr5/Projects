#include <stdio.h>
int fact(int);

int main (void)
{
	printf ("%d\n", fact (4));
}

int fact (int n)
{
	if (n == 0)
		return 1;
	return n * fact (n-1);
}
