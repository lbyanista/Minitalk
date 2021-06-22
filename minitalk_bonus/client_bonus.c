/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:48:33 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/22 15:15:36 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	usage(void)
{
	write(1, "usage: ./client [server-pid] [message]\n", 39);
	exit(0);
}

void	send_char(int c, int pid)
{
	int		i;
	int		bit;

	i = 7;
	while (i >= 0)
	{
		bit = c & 1;
		if (bit == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(90);
		c = c >> 1;
		i--;
	}
}

void	send_str(int pid, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		usage();
	send_str(ft_atoi(av[1]), av[2]);
	return (0);
}
