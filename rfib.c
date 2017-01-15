#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *mem;

int rfib(int n)
{
	if( n <= 1 )
	{
		return (1);
	}
	else
	{
		return (rfib(n - 1) + rfib(n - 2));
	}
}

int dfib(int n)
{
	int i;


	if(mem[n] == -1)
	{

	if(n <= 1)
	{
		mem[n] = 1;
	}
	else
	{
		mem[n] = (dfib(n - 1) + dfib(n - 2));
	}
	}
	return (mem[n]);
}


int main(int argc, char **argv)
{
	int i;
	int n;
	int *mem;

	n = atoi(argv[1]);

	mem = (int*)malloc(sizeof(int) * n + 1);
	i = 0;
	while(i <= n)
	{
		mem[i] = -1;
		i++;
	}

	clock_t begin = clock();
	printf("%d\n", dfib(n));
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", time_spent);


	return (0);
}
