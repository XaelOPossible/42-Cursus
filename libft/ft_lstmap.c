/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:07:53 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/12 16:58:03 by axemicha         ###   ########.fr       */
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
