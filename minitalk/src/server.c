/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:15:00 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/19 13:26:58 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmaster/include/libmaster.h"
#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

/*
** Handler appelé à chaque signal reçu.
** Construit chaque caractère bit par bit,
** puis assemble les caractères dans la chaîne message.
*/
void	ft_signal(int sig, siginfo_t *info, void *context)
{
	static int		bit_count = 0;
	static char		current_char = 0;
	static char		*message = NULL;

	(void)context;
	if (sig == SIGUSR2)
		current_char |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
		{
			ft_printf("%s\n", message);
			free(message);
			message = NULL;
			kill(info->si_pid, SIGUSR1);
			usleep(100);
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			char	tmp[2] = { current_char, '\0' };
			message = ft_strjoin_and_free(message, tmp);
			if (!message)
				exit(1);
			kill(info->si_pid, SIGUSR1);
		}
		bit_count = 0;
		current_char = 0;
	}
	else
		kill(info->si_pid, SIGUSR1);
}

/*
** Initialise les signaux et lance le serveur.
** Affiche son propre PID pour que le client puisse l'utiliser.
*/
int	main(void)
{
	struct sigaction	sa;

	ft_printf("SERVER PID : %d\n", getpid());
	sa.sa_sigaction = ft_signal;
	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

