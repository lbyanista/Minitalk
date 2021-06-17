/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:19:22 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/17 11:20:16 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*c;

	i = 0;
	c = (char *)malloc(sizeof(*c) * ((ft_strlen(str)) + 1));
	if (c == 0)
		return (0);
	while (str[i])
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}