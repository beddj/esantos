#include <stdio.h>

void passconst(const int *num1, int *num2);

int main ()
{
	const int	 i = 500;
	int			 j;
	
	j = 42;

	passconst(&i, &j);
	printf("%d\n", j);
	return (0);
}

void passconst(const int *num1, int *num2)
{
	*num2 = *num1;
}










