#include <omp.h>
#include <stdio.h>
#define N 100000


int main()
{
	FILE *fp;
	fp = fopen("prime.txt","w");
	int i,j;
	int num=0;
	//#pragma omp parallel for reduction(+:num) private(j) 
	for( i=2; i<N; i++)
	{
		for(j=2; j<i; j++)
			if (i%j==0) break;
			if (j>=i)
			{
				num++;
				fprintf(fp,"%d\n",i);
			}
		//num+=isPrime(i);
	}
	printf("素数共有%d个\n",num);

}
