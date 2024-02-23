#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	if (sign == 1)
		res = -res;
	return (res);
}

int	main(int ac, char **av)
{
	int	i;
	int	nb;
	int	u;

	i = 0;
	if (ac == 3)
	{
		while (av[2][i])
		{
			nb = av[2][i];
			u = 0;
			while (u != 7)
			{
				if (nb % 2 == 0)
					kill(ft_atoi(av[1]), SIGUSR1);
				else
					kill(ft_atoi(av[1]), SIGUSR2);
				nb /= 2;
				u++;
				usleep(250);
			}
			i++;
		}
	}
}
