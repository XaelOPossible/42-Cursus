/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:44:14 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/15 10:44:17 by axemicha         ###   ########.fr       */
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
