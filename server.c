/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:51:47 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/11 14:07:29 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
    pid_t pid;
    
    pid = getpid();
    printf("%d\n", pid);
    int h;

    h = fork();
    if (h == 0)
    {
        client(pid, "helloWorld!");
    }
    
    return (0);
}