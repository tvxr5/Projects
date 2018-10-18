// Tarun Vittal
// cs3750 PA 4
// 04/03/2017

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//file contains function prototype/header for isANumber function
#include "func.h"

int main(int argc, char *argv[]) //takes in number of commandline arguments and and array of commandline arguments 
{

	int total = 0;  // initialzes variable for total interger addition calculation, and sets it to zero
	int i = 0;  // counter variable

	// we read all the arguments and sum only the arguments which are 
	// integers
	for (i = 1; i < argc; i++)
	{
		if(isANumber(argv[i])) // isANumber function is called 
			total = total + atoi(argv[i]); // total of integers is calculated, by addung to previous total of integers added
	}
	
	//printing the sum of all integers
	printf("Total integers: %d\n" , total);
	
	for (i = 1; i < argc; i++)
	{
		//if argument is not a integer but a word/string it search for future occurances within another string. 
		if(isANumber(argv[i]) == 0)
		{
			int j = 0; 
			
			//if argument is found in any future argument we print it as a substring of the future occurance
			for (j = i + 1; j < argc; j++)
			{
				if (strstr (argv[j], argv[i]))
					printf("%s is a substring of %s\n" , argv[i] , argv[j]);
			}
		}
	}
	
	return 0; //exits program
}

