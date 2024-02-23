#include "minitalk.h"

int	ft_pow(int j)
{
	int	result;

	result = 1;
	if (j == 0)
		return (2);
	while (j >= 0)
	{
		result *= 2;
		j--;
	}
	return (result);
}

int	ft_atoi_binaire(char *nbr)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 7;
	result = 0;
	while (nbr[i])
	{
		if (nbr[i] == '1')
		{
			result += ft_pow(j);
		}
		j--;
		i++;
	}
	result = result / 2;
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int k)
{
	if (k > 9)
		ft_putnbr(k / 10);
	ft_putchar((k % 10) + '0');
}
