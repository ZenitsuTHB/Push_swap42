/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:28:58 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/31 22:18:59 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	void rev_rotate(t_node ***stack)
{
	t_node *current;
	t_node *new_head;

	current = *(*stack);
	new_head = *(*stack);
	while (current->next->next != NULL)
		current = current->next;
	current->next->next = new_head;
	new_head = current->next;
	current->next = NULL;
	*(*stack) = new_head;
}

void	rra(t_node **stack_a)
{
	rev_rotate(&stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_node **stack_b)
{
	rev_rotate(&stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rev_rotate(&stack_a);
	rev_rotate(&stack_b);
	ft_putendl_fd("rrr", 1);
}
