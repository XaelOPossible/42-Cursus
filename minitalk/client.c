/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:13:11 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/18 13:21:19 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_bit_control;

void	send_char(char c, pid_t pid)
{
	int	bit;
	
	bit = __CHAR_BIT__ * sizeof(c) - 1;
	while (bit >= 0)
	{
		if (kill)
	}
}
