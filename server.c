/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:51:47 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/19 17:38:29 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int sig)
{
	// static unsigned char	i;
	// static unsigned char	r;
	// static unsigned char tmp;

	// tmp = 1;

	// // printf("*\n");
	// //printf("%d\n", sig);
	// if (sig == SIGUSR1)
	// 	printf("1\n");
	// else
	// 	printf("0\n");
	
	
	// if (sig == SIGUSR1)
	// 	r = r | tmp;
	// tmp = tmp << 1;
	// i++;
	// 	// i += r << 1;
	// // r++;
	// if (i == 8)
	// {
	// 	ft_putchar(i);
	// 	// write(1, &i ,1);
	// 	i = 0;
	// 	r = 0;
	// 	tmp = 1;
	// }

	static int				n_bits = 0;
	static unsigned char	c = 0;
	static unsigned char	tmp_bit = 1;

	if (sig == SIGUSR1)
		c = c | tmp_bit;
	tmp_bit = tmp_bit << 1;
	n_bits++;
	if (n_bits == 8)
	{
		ft_putchar(c);
		n_bits = 0;
		tmp_bit = 1;
		c = 0;
	}
}

// static volatile int signalPid = -1;
// void    get_pid_c(int sig, siginfo_t *info)
// {
//     signalPid = info->si_pid;
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	lens1;
// 	int		i;
// 	char	*p;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	lens1 = ft_strlen(s1);
// 	i = 0;
// 	p = malloc(sizeof(char *) * (lens1 + ft_strlen(s2)));
// 	if (p == 0)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		p[i] = s1[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (s2[i])
// 	{
// 		p[i + lens1] = s2[i];
// 		i++;
// 	}
// 	p[i + lens1] = '\0';
// 	return (p);
// }

// void	ft(int nb)
// {
// 	static char *str;// [1][0][][][][][][] power = 2 7 - power 

// 	if (!str)
// 		str = ft_strdup("");
// 	if (nb == 31)
// 		str = ft_strjoin(str, "1\0");
// 	else if (nb == 30)
// 		str = ft_strjoin(str, "0\0");
// 	if (ft_strlen(str) == 8)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 		str = NULL;
// 	}

// 	// char	c;
// 	// int		i;

// 	// i = 0;
// 	// c = '\0';
// 	// c += (nb << i++);
// 	// if (i > 7)
// 	// {
// 	// 	if (c == '\0')
// 	// 		ft_putchar('\n');
// 	// 	else
// 	// 		ft_putchar(c);
// 	// 	c = 0;
// 	// 	i = 0;
// 	// }
// }

int	main(int ac, char **av)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("server pid: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR2, send_char);
	signal(SIGUSR1, send_char);
	while (1)
		pause();
	return (0);
}
