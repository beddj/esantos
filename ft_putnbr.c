#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int num)
{
	if(num < 0)
	{
		ft_putchar('-');
		num = -num;

	}
	if(num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}

	else
	{
		ft_putchar(num + '0');
	}

}

int main (void)
{

	ft_putnbr(-42);

	return (0);

}
