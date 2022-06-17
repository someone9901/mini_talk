/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamssafi <aamssafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:59:33 by aamssafi          #+#    #+#             */
/*   Updated: 2022/05/08 18:33:09 by aamssafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	if (nb < 10)
		ft_putchar (nb + 48);
}

void	signal_handl(int sig)
{
	static char	i;
	static int	j;

	if (sig == SIGUSR1)
		i += (1 << (7 - j));
	j++;
	if (j == 8)
	{
		ft_putchar(i);
		j = 0;
		i = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, signal_handl);
	signal(SIGUSR2, signal_handl);
	write(1, "PID IS :", 9);
	ft_putnbr(getpid());
	ft_putchar('\n');
	write(1, "SERVER IS WAITING FOR SIGNALS...\n", 34);
	while (1)
		pause();
}
