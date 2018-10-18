// Tarun Vittal
// cs2750 PA 3
// 03/20/2018

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "avg.h"		//headerfiles
#include "sum.h"
#include "max.h"
#include "min.h"

#define N 10

int main(){
  int i;      // count vaiable/integer
  float a[N]; // intalzes array of siz N , 10 in this case as defined
  srand(123);

  printf("\n\n");
  for (i = 0; i < N; i++){	// makes a random array of flosts using rand
    a[i] = ((double) rand())/ RAND_MAX;
    printf("%.2f ",a[i]);
  }

  printf("\n\n");			//prints/calls functions for various 
  printf("average: %.2f\n",avg(a,N));	// stats of array with prototypes
  printf("sum: %.2f\n",sum(a,N));
  printf("max: %.2f\n",max(a,N));
  printf("min: %.2f\n",min(a,N));
  printf("\n\n");

  return 0;
}
