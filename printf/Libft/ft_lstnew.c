/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:18:44 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/12 15:20:40 by axemicha         ###   ########.fr       */
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
