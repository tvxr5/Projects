#if 0
gcc $0 -g -ansi -std=c99 -o exe && ./exe
exit
#endif




#include <stdio.h>

#define abs1(x)  (x<0)?-x:x
#define abs2(x)  ((x<0)?-x:x)
#define abs3(x)  ((x<0)?-(x):x)
#define abs4(x)  ((x) < 0 ? -(x):(x))
#define abs5(x)  (((x)<0)?-(x):(x))


#define test(x)     printf("//%30s=%d\n", #x, x);
#define testt(t,x)  printf("//%15s%15s=%d\n", t, #x, x);

int main()
{
	test(abs4(2147483648));
	test(abs4(1));
	test(abs4(2));
	test(abs4(3));
	test(abs4(4));
	test(abs4(5));	
	test(abs4(6));
	test(abs4(7));
	test(abs4(8));
	test(abs4(9));
	test(abs4(10));
	test(abs4(11));
	test(abs4(12));
	test(abs4(20));
	test(abs4(30));



}
   
