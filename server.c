/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:51:47 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/17 17:58:42 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int sig)
{
	static int i = 0;
	static int r = 0;

	if (sig == SIGUSR1)
		i += 1 << (7 - r);
	r++;
	if (r == 8)
	{
		ft_putchar(i);
		i = 0;
		r = 0;
	}
}

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

int main(int ac, char **av)
{
	pid_t pid;

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