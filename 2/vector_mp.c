#include <stdio.h>
#include <omp.h>
#include <time.h>
#define N 1000
//#define N 100000
//reduction
int main()
{
	clock_t start,finish;
	double totaltime;
	start=clock();
	long int i,n;
	float a[N],b[N],result;
	// initializations
	//n = 1000;
	result = 0.0;
	for (i=0; i<N; i++)
	{
		a[i] = i+1.5;
		b[i] = i+2.5;
	}
	#pragma omp parallel for private(i) reduction(+:result)
	for (i=0; i<N; i++)
	{
		result = result + (a[i] * b[i]);
	}
	printf ("a*b=%12.6lf\n",result);
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	printf ("run time=%8.6lfs\n",totaltime);
	return 0;
}

