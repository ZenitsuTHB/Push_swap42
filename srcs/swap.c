/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:09:54 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/27 20:13:04 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_node *first, t_node *second)
{
	first->next = second->next;
	second->next = first;
}

void	sa(t_node *stack_a)
{
	t_node	*first;
	t_node	*second;

//store the pointer to the first and 2nd node
	first = stack_a;
	second = stack_a->next;
	swap(first, second);
	second = stack_a;
	ft_putendl_fd("sa", 1);
}

void	sb(t_node *stack_b)
{
	t_node	*first;
	t_node	*second;

	first = stack_b;
	second = stack_b->next;
	swap(first, second);
	second = stack_b;
	ft_putendl_fd("sb", 1);
}

void	ss(t_node *stack_a, t_node *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putendl_fd("ss", 1);
}
