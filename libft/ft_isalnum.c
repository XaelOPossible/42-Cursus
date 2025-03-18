/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:42:50 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/08 15:35:01 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c < 65 || c > 90) && (c < 97 || c > 122))
		&& (c < 48 || c > 57))
	{
		return (0);
	}
	return (1);
}
