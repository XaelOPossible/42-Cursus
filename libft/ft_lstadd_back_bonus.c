/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:43:49 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/15 10:43:52 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastobjt;

	if (lst)
	{
		if (*lst)
		{
			lastobjt = ft_lstlast(*lst);
			lastobjt->next = new;
		}
		else
		{
			*lst = new;
		}
	}
}
