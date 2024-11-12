/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:24:49 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/12 13:52:49 by axemicha         ###   ########.fr       */
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
