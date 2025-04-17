/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:36:31 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/17 12:28:30 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_index(t_stack *head, int size)
{
	int		index;
	t_stack	*tmp;
	t_stack	*min;

	index = 0;
	while (index < size)
	{
		tmp = head;
		min = NULL;
		while (tmp)
		{
			if (tmp->index == -1 && (!min || tmp->value < min->value))
				min = tmp;
			tmp = tmp->next;
		}
		if (min)
			min->index = index++;
		else
			break ;
	}
}

static t_stack	*init_from_array(char **array)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 0;
	while (array[i])
	{
		insert_at_tail(&stack, ft_atoi(array[i]));
		i++;
	}
	return (stack);
}

t_stack	*init_list(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**tmp;

	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (!tmp)
			return (NULL);
		stack_a = init_from_array(tmp);
		ft_free(tmp);
	}
	else
		stack_a = init_from_array(argv + 1);
	return (stack_a);
}
