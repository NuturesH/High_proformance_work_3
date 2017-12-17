#include <stdio.h>
#define N 100000
main()
{
int i,k,n;
int j=0;
FILE *fp;	
int prime[N];



fp = fopen("3-acc.txt","w");
//#pragma acc kernels
for (i = 3;i<=N;i++)
	{
        n = 0;
        //prime[i] = 0;
        #pragma acc kernels
		for ( k = 2;k<i;k++)
			{
			if(i%k == 0) 
                n += 1;
			}
		if (n == 0)
			{
			prime[j] = i,
			j++;
			}
	}
for (i = 0; i < j ; i++)
{
    fprintf(fp,"%d\n",prime[i]);
}
fclose(fp);
printf("prime number : %d\n",j);
}
