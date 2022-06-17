/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamssafi <aamssafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 05:23:23 by aamssafi          #+#    #+#             */
/*   Updated: 2022/05/11 12:58:41 by aamssafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

void	conv_bin(int pid, char *str)
{
	int	a;
	int	b;

	while (*str)
	{
		a = 7;
		while (a >= 0)
		{
			b = ((*str >> a) & 1);
			if (b == 1)
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill (pid, SIGUSR2);
			}
			a--;
			usleep(150);
		}
		str++;
	}
}	

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 1)
			return (0);
		conv_bin(pid, av[2]);
	}
	else
		write(1, "WRONG NUMBER OF ARGUMENTS!\n", 28);
}
