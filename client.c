/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:56:06 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/17 18:08:43 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(char *str_error)
{
	write(2, str_error, ft_strlen(str_error));
	exit(1);
}

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

void	send_char(char ascii, int r, int pid)
{
	if (r > 0)
		send_char(ascii / 2, r - 1, pid);
	if ((ascii % 2) == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			error("Error sending the signal\n");
			exit(0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr("Error sending the signal\n");
			exit(0);
		}
	}
	usleep(100);
}

void	send_str(int pid, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], 7, pid);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 3)
		usage();
	send_str(ft_atoi(av[1]), av[2]);
	return (0);
}