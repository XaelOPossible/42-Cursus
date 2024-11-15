/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:44:43 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/15 10:44:48 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*object;
	void	*content;

	if (!lst || !del)
		return (0);
	lst2 = 0;
	while (lst)
	{
		content = f(lst->content);
		object = ft_lstnew(content);
		if (!object)
		{
			del(content);
			ft_lstclear(&lst2, del);
			return (0);
		}
		ft_lstadd_back(&lst2, object);
		lst = lst->next;
	}
	return (lst2);
}
