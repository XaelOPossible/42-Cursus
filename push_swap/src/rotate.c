/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:23:05 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/17 12:23:23 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	*head = (*head)->next;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rotate_a(t_stack **head)
{
	ft_rotate(head);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **head)
{
	ft_rotate(head);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}
