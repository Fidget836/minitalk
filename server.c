#include "minitalk.h"

char	g_bit[9];

void	init(char *init)
{
	int	i;

	init[8] = '\0';
	i = 0;
	while (i < 8)
	{
		init[i] = 'A';
		i++;
	}
}

char	*ft_replace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'A')
			str[i] = '0';
		i++;
	}
	return (str);
}

void	ft_assembleur(int signal)
{
	int	i;

	i = 0;
	if (signal == SIGUSR2)
	{
		while (g_bit[7 - i] != 'A')
			i++;
		g_bit[7 - i] = '1';
	}
	else
	{
		while (g_bit[7 - i] != 'A')
			i++;
		g_bit[7 - i] = '0';
	}
	if (i == 6)
	{
		i = 0;
		ft_replace(g_bit);
		ft_putchar(ft_atoi_binaire(g_bit));
		init(g_bit);
	}
}

int	main(int ac, char **av)
{
	pid_t	i;

	(void)av;
	i = getpid();
	write(1, "PID : ", 6);
	ft_putnbr(i);
	write(1, "\n", 1);
	init(g_bit);
	while (ac == 1)
	{
		signal(SIGUSR1, ft_assembleur);
		signal(SIGUSR2, ft_assembleur);
	}
	return (0);
}
