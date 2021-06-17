/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:47:59 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/11 19:49:55 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	unsigned int b;

	if (n < 0)
	{
		ft_putchar('-');
		b = n * -1;
	}
	else
		b = n;
	if (b >= 10)
		ft_putnbr(b / 10);
	ft_putchar(b % 10 + '0');
}