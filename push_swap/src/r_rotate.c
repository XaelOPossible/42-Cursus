#include "../includes/push_swap.h"

void	r_rotate(t_stack **head)
{
	t_stack *new_tail;
	t_stack *last_tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	new_tail = (*head)->next;
	last_tail = *head;
	while (last_tail ->next != NULL)
	{
		last_tail = last_tail->next;
	}
	last_tail->next = *head;
	(*head)->next = NULL;
	*head = new_tail;
}

void	r_rotate_a(t_stack **head)
{
	r_rotate_a(head);
	write(1, "rra", 2);
}

void	r_rotate_b(t_stack **head)
{
	r_rotate_b(head);
	write(1, "rrb", 2);
}
void	r_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	write(1, "rrr")
}


