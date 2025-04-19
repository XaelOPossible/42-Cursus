/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:01:55 by dmoreux           #+#    #+#             */
/*   Updated: 2025/04/19 13:28:12 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libmaster/include/libmaster.h"
# define ACK_SIGNAL 1
# define END_SIGNAL 2

extern volatile sig_atomic_t signal_status;
char	*ft_strjoin_safe(char *s1, char *s2);
char	*ft_strjoin_and_free(char *s1, char *s2);

#endif