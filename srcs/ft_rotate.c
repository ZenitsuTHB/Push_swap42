/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:37:55 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/01 20:48:45 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate(t_node **stack)
{
	t_node *newhead;
	t_node *current;
//	t_node *prev;

//	prev = NULL;
	newhead = (*stack)->next;
	current = (*stack);
	while(current->next != NULL)
	{
//		prev = current;
		current = current->next;
	}
//	prev->next = current;
//	current->next = (*stack);
//	(*stack)->next = NULL;
//	(*stack) = prev;
//	current = NULL;
	current->next = (*stack);
	(*stack)->next = NULL;
   	(*stack) = newhead;
//	newhead->next = (*stack)->next;
//	ft_clearnodes(&);
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}
