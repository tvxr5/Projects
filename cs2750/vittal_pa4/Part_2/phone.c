// Tarun Vittal
// cs2750 PA 4
// 04/03/2018


#include<stdio.h> 
#include<stdlib.h>

#include "phone_fmt.h"


int main()
{
	char arr[200]; //intialized array for two hundred command line arguments
	char result[14];  // intialized array for 14 characters of phone number 
	int c = 0; // integers used for counter purposes
	int i =0;
	int j = 1;


	result[0] = '('; // first element value of result array, used for phone number
	printf("\n Input: "); // Asks for user input
	scanf("%s", arr); //scans user input into array
	
	while(arr[i]!='\0' && c <10) // checks array of characters for numbers as long as it is continuous and there are 10 of them. 
	{
		if(checkDigit(arr[i])) // checks each character in array to see if it is a number
		{
			result[j] = arr[i]; // if a numbeer it is recorded in the result array, starting from second element
			j++; // adds to result array for taking in next element when detected
			c++;
			
			if(c == 3) //adds parenthesies and space after area code. 
			{
				result[j++] = ')';
				result[j++] = ' ';
			}
			
			if(c == 6) // adds dash after 6 phone number digits
			{
				result[j++] = '-';
			}
		}
		i++; //moves to next element in input array 
	}
	
	if(c<10)  //if there were not atleasr 10 numbers in the 200 or less continous command line characters input, gives error message
	{
		printf(" Invalid Input. Enter at least 10 digits.\n");
		printf(" Exiting Program. Please run again.\n"); 
	}

	else  // outputs phone number if 10 number arguments were entered. 
	{

		printf(" Output: %s \n", result);  
		printf(" Exiting Program. Please run again for another string.\n");
	}

	return 0; // ends program
}
