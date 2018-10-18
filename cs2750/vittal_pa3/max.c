// Tarun Vittal
// cs2750 PA 3
// 03/20/2018

float max(float a [] , int N){
  float max = a[0];		//Takes the first value of a as max
  for (int i = 1; i < N; i++){	//compares it to the other values in array a
    if(max < a[i]){		// and assigns the largest value to max
      max = a[i];
    }
  }
  return max;			// returns max
}
