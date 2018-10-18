// Tarun Vittal
// cs2750 PA 4
// 04/03/2018

#include<ctype.h>

//function to check if the entered arguments are numbers. 
int isANumber (char *p)
{
	char *temp = p;  
	
	while (*temp)
	{
		if (!isdigit(*temp)) //checks if command line argument is a not a number, and returns 0 if true
			return 0; 
		temp++;
	}

	return 1;  //else returns one
}
