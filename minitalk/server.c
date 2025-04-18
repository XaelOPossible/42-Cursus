/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:28:33 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/18 04:59:56 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libmaster/include/libmaster.h"

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int	bits_received = 0;
	static char	buffer = 0x0;

	(void)context;
	if (signal == SIGUSR1)
	{
		buffer = buffer | (0x01 << bits_received % 8);
	}
	if (bits_received % 8 == 7)
	{
		if (buffer == '\0')
		{
			usleep(256);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &buffer, 1);
		buffer = 0x0;
	}
	bits_received++;
	usleep(256);
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = &ft_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
}
