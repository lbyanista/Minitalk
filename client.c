/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:56:06 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/11 14:08:57 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int client(pid_t pid, char *str)
{
    printf("the server pid is: %d\n", pid);
    printf("the msg is: %s\n", str);
    return (0);
}