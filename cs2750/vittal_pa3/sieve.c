// Tarun Vittal
// cs2750 PA 3
// 03/24/2018

#include <stdio.h>
#include <stdlib.h>
 
int main(){
  unsigned long long int i,j; //initialzes variables that can be  large values 
  int *primes; //intializes a pointer called primes
  int N = 100000; // size of the number of integers we will be looking through

  primes = malloc(sizeof(int) * N); // allocates an array capable of holding
				    // a 100,000 integers

  for (i = 2;i < N; i++){ //starts at 2 as 0 and one are not considered prime
    primes[i] = 1;        // fills array callled primes with ones. 
  }
 
  for (i = 2;i < N; i++){	//Marks all the multiples of i with j to be zero
    if (primes[i]){		// makes sure the values checked are less than
      for (j = i;i * j < N; j++){ // the sqrt of N, 
        primes[i * j] = 0;        // marks all multiples of i as 0;       
      }
    }
  }

  for (i = 2;i < N; i++){ //prints primes
    if (primes[i]){
      printf("%d\n", i);
    }
  }

  return 0; //ends program
}

