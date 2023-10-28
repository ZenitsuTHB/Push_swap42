/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:37:55 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/27 20:12:59 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_node **stack)
{
	t_node *new;
	t_node *current;

	new = (*stack)->next;
	current = (*stack);
	while(current->next != NULL)
		current = current->next;
	current->next = (*stack);
	(*stack)->next NULL;
}

void	ra(t_node **stack_a)
{
	rotate(&stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_node **stack_b)
{
	rotate(&stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(&stack_a);
	rotate(&stack_b);
	ft_putendl_fd("rr", 1);
}
