/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:41:41 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/17 12:22:52 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_nodes(t_stack *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	print_list(t_stack *head)
{
	t_stack	*current;
	int		i;

	current = head;
	i = 0;
	while (current != NULL)
	{
		printf("node: %d: %d index: %d\n", i, current->value, current->index);
		i++;
		current = current->next;
	}
}

t_stack	*make_new_node(int new_value)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = new_value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	insert_at_tail(t_stack **head, int new_value)
{
	t_stack	*new_node;
	t_stack	*current;

	if (*head == NULL)
	{
		*head = make_new_node(new_value);
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	new_node = make_new_node(new_value);
	current->next = new_node;
}
