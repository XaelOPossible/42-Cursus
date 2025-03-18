#include "../includes/push_swap.h"

void	ft_swap(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || (*head)->next == NULL)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	swap_a(t_stack **head)
{
	ft_swap(head);
	write(1, "sa", 2);
}

void	swap_b(t_stack **head)
{
	ft_swap(head);
	write(1, "sb", 2);
}
void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss")
}
