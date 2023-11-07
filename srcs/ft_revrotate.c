/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:28:58 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/07 20:41:38 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	void	rev_rotate(t_node **stack)
{
	t_node	*current;
	t_node	*new_head;

	current = *stack;
	new_head = *stack;
	while (current->next->next != NULL)
		current = current->next;
	current->next->next = new_head;
	new_head = current->next;
	current->next = NULL;
	*stack = new_head;
}
//	t_node	*current;
//	t_node	*old_head;
//	t_node	*new_head;
//	t_node	*new_tail;
//
//	old_head = *stack;
//	new_head = NULL;
//	new_tail = NULL;
//	current = *stack;
//	while (current->next)
//	{
//		new_tail = current;
//		current = current->next;
//	}
//	new_head = current;
//	*stack = new_head;
//	new_head->next = old_head;
//	new_tail->next = NULL;

void	rra(t_node **stack_a)
{
	rev_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_node **stack_b)
{
	rev_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
