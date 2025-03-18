#include "../includes/push_swap.h"

void	ft_rotate(t_stack **head)
{
	t_stack *new_tail;
	t_stack *last_tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last_tail = *head;
	while (last_tail ->next != NULL)
	{
		new_tail = last_tail;
		last_tail = last_tail->next;
	}
	last_tail->next = *head;
	new_tail->next = NULL;
	*head = last_tail;
}

void	rotate_a(t_stack **head)
{
	ft_rotate(head);
	write(1, "ra", 2);
}

void	rotate_b(t_stack **head)
{
	ft_rotate(head);
	write(1, "rb", 2);
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr")
}
