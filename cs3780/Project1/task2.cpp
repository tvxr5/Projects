#include <iostream>
using namespace std; 


int main()
{

	int staticArray[5] = { 16, 2, 77, 40, 12071 }; 
	
	int * dynamicPtr;
	int size = 5;  
	dynamicPtr = new int [size];
	for(int i = 0; i <size; i++) 
	{
		dynamicPtr[i] = i+1;   
	}
}
