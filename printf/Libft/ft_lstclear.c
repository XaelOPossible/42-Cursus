/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:03:00 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/12 13:50:13 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*stock;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		stock = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = stock;
	}
}
