/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:30:52 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/17 12:31:35 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rrotate(t_stack **head)
{
	t_stack	*prev;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	prev = NULL;
	last = *head;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *head;
	*head = last;
}

void	r_rotate_a(t_stack **head)
{
	ft_rrotate(head);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack **head)
{
	ft_rrotate(head);
	write(1, "rrb\n", 4);
}

void	r_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
	write(1, "rrr\n", 4);
}
