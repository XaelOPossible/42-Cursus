/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin 42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:56:47 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/19 13:45:00 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t	signal_status = 0;

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		signal_status = 1;
	else if (sig == SIGUSR2)
		signal_status = 2;
}

/*
** Envoie chaque bit du caractère c au serveur via signaux.
** Attend un ACK (SIGUSR1) après chaque bit pour synchronisation.
*/
void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		signal_status = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		while (signal_status != 1)
			pause();
		i--;
	}
}

/*
** Envoie chaque caractère de la chaîne à l’aide de send_char.
** Termine par l’envoi du caractère nul '\0'.
*/
void	send_message(pid_t pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
}

/*
** Point d'entrée du client.
** Initialise les handlers et envoie le message au serveur.
*/
int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <MESSAGE>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_message(server_pid, argv[2]);
	while (signal_status != 2)
		pause();
	ft_printf("✅ Message bien reçu par le serveur !\n");
	return (0);
}


