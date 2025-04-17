/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:41:00 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/17 12:32:24 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bring_to_top(t_stack **stack, int pos, char stack_name)
{
	int	size;

	size = count_nodes(*stack);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			if (stack_name == 'a')
				rotate_a(stack);
			else
				rotate_b(stack);
		}
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
		{
			if (stack_name == 'a')
				r_rotate_a(stack);
			else
				r_rotate_b(stack);
		}
	}
}

static int	push_chunk_to_b(t_stack **a, t_stack **b, int start, int end)
{
	t_stack	*tmp;
	int		pos;

	tmp = *a;
	pos = 0;
	while (tmp)
	{
		if (tmp->index >= start && tmp->index <= end)
		{
			bring_to_top(a, pos, 'a');
			push_b(a, b);
			if ((*b)->index < (start + end) / 2)
				rotate_b(b);
			return (1);
		}
		pos++;
		tmp = tmp->next;
	}
	return (0);
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	int	chunk_size;
	int	start;
	int	end;
	int	size;
	int	max_pos;

	size = count_nodes(*a);
	chunk_size = 20;
	start = 0;
	end = chunk_size - 1;
	while (start <= size)
	{
		if (!push_chunk_to_b(a, b, start, end))
		{
			start += chunk_size;
			end += chunk_size;
		}
	}
	while (*b)
	{
		max_pos = get_position(*b, find_biggest(*b));
		bring_to_top(b, max_pos, 'b');
		push_a(a, b);
	}
}
