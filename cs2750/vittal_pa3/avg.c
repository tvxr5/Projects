// Tarun Vittal
// cs2750 PA 3
// 03/20/2018

float avg(float a [] , int N){ //takes in an array of floats a of size N 
  float sum = 0;		       // initializes  a float value called sum 	
  for(int i = 0; i < N; i++){      // adds all values in float array a 
    sum += a[i];                     
  }
  return sum/N;                // divides the sum by N, and return the avg. 
}
