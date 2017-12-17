#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000
//#define N 100000

int main()
{

	clock_t start,finish;
	double totaltime;
	start = clock();
	float a[N], b[N],result=0.0;
	for (int i = 0; i< N; i++)
	{
		a[i] = i+1;
		b[i] = i+2;

	}
	#pragma acc kernels
	for (int i = 0; i < N; i++)
	{	
		
		result = result + (a[i]* b[i]);
	}
	printf ("a*b=%12.6lf\n",result);
	finish  = clock();
	totaltime = (double)(finish-start)/CLOCKS_PER_SEC;
	printf ("run time =%8.6lfs\n",totaltime);	

	return 0;

}
