/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:28:15 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/18 04:59:49 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libmaster/include/libmaster.h"

void	ft_send_string(pid_t pid_init, char *message_init)
{
	static int		current_bit = 0;
	static pid_t	pid = 0;
	static char		*message = NULL;
	int				signal;
	int				zeroes;

	if (pid_init)
		pid = pid_init;
	if (message_init)
		message = message_init;
	if (current_bit % 8 == 0)
		zeroes = 0;
	if (message[current_bit / 8] & (0x01 << (current_bit % 8)))
		signal = SIGUSR1;
	else
	{
		signal = SIGUSR2;
		zeroes++;
	}
	current_bit++;
	usleep(0x80);
	if (kill(pid, signal) || zeroes == 8)
		exit(0);
}

void	ft_handler(int signal)
{
	if (signal == SIGUSR2)
		ft_send_string(0, NULL);
	if (signal == SIGUSR1)
		exit(-1);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("usage: %s [PID] [message]\n", argv[0]);
		return (-1);
	}
	if (ft_atoi(argv[1]) == -1)
	{
		ft_printf("Let's just not do that..");
		return (-1);
	}
	signal(SIGUSR1, &ft_handler);
	signal(SIGUSR2, &ft_handler);
	ft_send_string(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
