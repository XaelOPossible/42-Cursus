/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:34:01 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/17 12:36:23 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libmaster/include/libmaster.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		count_nodes(t_stack *head);
void	print_list(t_stack *head);
t_stack	*make_new_node(int new_value);
void	insert_at_tail(t_stack **head, int new_value);
void	set_index(t_stack *head, int link_size);
t_stack	*init_list(int argc, char **argv);

// focntion error et parsing

int		check_doubles(char **argv);
int		check_nbr(char *argv);
void	check_input(int argc, char **argv);

// fonction utilitaire

int		count_params(char **argv);
void	error_msg(char *str);
char	**ft_free(char **s);
void	free_stack(t_stack **head);
int		sorted(t_stack *head);
int		get_position(t_stack *stack, int index);

// fonction de tri

void	bring_to_top(t_stack **stack, int pos, char stack_name);
void	chunk_sort(t_stack **a, t_stack **b);

int		find_biggest(t_stack *head);
int		find_bits(int biggest_nbr);

void	sort_three(t_stack **head);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
// void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

void	ft_push(t_stack **stack_from, t_stack **stack_to);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

void	ft_swap(t_stack **head);
void	swap_a(t_stack **head);
void	swap_b(t_stack **head);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);

void	ft_rotate(t_stack **head);
void	rotate_a(t_stack **head);
void	rotate_b(t_stack **head);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);

void	ft_rrotate(t_stack **head);
void	r_rotate_a(t_stack **head);
void	r_rotate_b(t_stack **head);
void	r_rotate_ab(t_stack **stack_a, t_stack **stack_b);

#endif
