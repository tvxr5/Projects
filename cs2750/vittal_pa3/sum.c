// Tarun Vittal 
// cs2750 PA 3
// 03/20/2018

float sum(float a [], int N){
  float sum = 0;			//assigns the value of 0 to float sum
  for(int i = 0; i < N; i++){		// adds all elements in array
    sum += a[i];			
  }
  return sum;				// returns sum 
}
