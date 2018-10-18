#include <iostream>
using namespace std; 


void functionThree(int c)
{

	int z = 8;  
}


void functionTwo(int b)
{

        int y = 7;
        functionThree(y);
}

void functionOne(int a)
{
        int g = 4;
        functionTwo(g);
}


int main()
{
 

	int d = 2; 
	functionOne(d); 
	
	return 0; 
}
