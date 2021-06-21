/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:56:06 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/21 12:11:48 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	error(char *str_error)
// {
// 	write(2, str_error, ft_strlen(str_error));
// 	exit(1);
// }

void	usage(void)
{
	write(1, "usage: ./client [server-pid] [message]\n", 39);
	exit(0);
}

// void	send_char(int pid, unsigned char byte)
// {
// 	int		counter;

// 	counter = 1 << 6;
// 	while (counter)
// 	{
// 		if (byte & counter)
// 		{
// 			if (kill(pid, SIGUSR1) == -1)
// 				error("bad pid\n");
// 		}
// 		else
// 		{

// 			if (kill(pid, SIGUSR2) == -1)
// 				error("bad pid\n");
// 		}
// 		counter >>= 1;
// 		usleep(600);
// 	}
// }

// void	main_handler(char *strpid, char *msg)
// {
// 	int			pid;

// 	pid = ft_atoi(strpid);
// 	while (*msg)
// 	{
// 		send_char(pid, *msg);
// 		++msg;
// 	}
// 	send_char(pid, *msg);
// }

// void	done(int n)
// {
// 	(void)n;
// 	printf("Done\n");
// }

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
	// 01100001 ==> 00110000 ==> 00011000
	// 01100010
	// 11011001 10000001
	// c >> 10000

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
