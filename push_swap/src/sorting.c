/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:52:17 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/17 12:22:31 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		swap_a(a);
	else if (first > second && second > third)
	{
		swap_a(a);
		r_rotate_a(a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first < second && second > third && first < third)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (first < second && second > third && first > third)
		r_rotate_a(a);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;

	while (count_nodes(*stack_a) > 3)
	{
		pos = get_position(*stack_a, 0);
		if (pos == -1)
			pos = get_position(*stack_a, 1);
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			push_b(stack_a, stack_b);
		else if (pos <= count_nodes(*stack_a) / 2)
			rotate_a(stack_a);
		else
			r_rotate_a(stack_a);
	}
	sort_three(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		swap_b(stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	if (sorted(*stack_a))
		return ;
	size = count_nodes(*stack_a);
	if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		chunk_sort(stack_a, stack_b);
}
