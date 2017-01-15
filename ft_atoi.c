#include <stdio.h>

int ft_atoi(char *str)
{
	int i;
	int nbr;
	int neg;

	i = 0;
	neg = 0;
	nbr = 0;
	while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;

	if(str[i] == '-')
		neg = 1;
	if(str[i] == '+' || str[i] == '-')
		i++;

	while(str[i] != '\0')
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if(neg == 1)
		return (-nbr);
	else
		return (nbr);
}


int main ( int argc, char **argv)
{
	char *num;

	num = argv[1];

	if (argc != 2)
		printf("ERROR: wrong number of paramters");

	printf("%d\n", ft_atoi(num));

	return (0);
}
