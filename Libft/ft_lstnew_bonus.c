/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:44:55 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/15 10:44:58 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*listch;

	listch = (t_list *)malloc(sizeof(*listch));
	if (listch == NULL)
		return (NULL);
	listch->content = content;
	listch->next = NULL;
	return (listch);
}
