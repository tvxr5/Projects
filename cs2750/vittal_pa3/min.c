// Tarun Vittal
// cs2750 PA 3
// 03/20/2018

float min(float a [], int N){
  float min = a[0];		// assigns min to first element
  for(int i = 1; i < N; i++){	// compares it to all other elements in array a
    if(min > a[i]){   		// assigns the least value of array a to min
      min = a[i];
    }
  }
  return min;			//returns min
}
