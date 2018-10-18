#include <iostream>
#include<bits/stdc++.h>
using namespace std; 

int main()
{

	 
	signed int firstNumber, secondNumber, sumOfTwoNumbers, productOfTwoNumbers, quotientOfTwoNumbers;
     

	// cout <<" Max Int is: " << INT_MAX << endl;  // used for clarity during testing. 
		
	cout << "Enter two numbers that will be multiplied and divided. Number 1 will be divided by Number 2." << endl;
	
	cout << "Enter number 1: "; 
        cin >> firstNumber; 
	cout << endl; 
	
	cout << "Enter number 2: "; 
	cin >> secondNumber; 
	
	if( firstNumber > (INT_MAX - secondNumber)) 
	{	
		cout << endl;
		cout << "Error: The firstNumber would cause an interger overflow issue. Please try again with inbound inputs." << endl;
	}
	
	if (secondNumber > (INT_MAX - firstNumber))
	{
		cout << endl;
		cout  << "Error: The secondNumber would cause an integer overflow issue. Please try again with in bound inputs." << endl;  
	}

	
	if (secondNumber > (INT_MAX/firstNumber)) 
	{
		cout << endl;
		cout << "Error: This will cause an integer overflow issue, as if Number 1 and Number 2 are multiplied it will be longer than an signed int. Please Try again with in bound input." << endl;  
	} 

	int x = firstNumber%secondNumber; 

	if (x != 0)
        {	
		cout << endl;
                cout << "Error: The two integers input do not divide perfectly and would require a double not a int to properly dispalay output. Please try again." << endl;
		cout << "They would have a remainder of " << x << endl;  
        	cout << endl; 
	} 
	
	else 
	{
    	
	cout << endl;
	
	
	//Addition
	sumOfTwoNumbers = firstNumber + secondNumber;
	cout << "Sum = " << sumOfTwoNumbers << endl; 
	cout << endl; 

	// Multiplication
	productOfTwoNumbers = firstNumber * secondNumber;
	cout << "Product = " << productOfTwoNumbers << endl; 
	
	cout << endl;
	
	//Division
	quotientOfTwoNumbers = firstNumber/secondNumber;
	cout << "Quotient = " << quotientOfTwoNumbers << endl;
	

	}
		
	return 0;  
	
}
