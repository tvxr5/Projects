// Tarun Vittal
// cs2750 PA 4
// 04/03/2018

#include<ctype.h>

//function to check the if the characters entered are numbers 
int checkDigit(char c)
{
	if(c>= '0' && c<= '9')
	{
		return 1;
	}
	
	else
	{
		return 0 ;
	}
}
