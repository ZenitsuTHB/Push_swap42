/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:09:54 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/30 16:21:23 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_node **stack, t_node *first, t_node *second)
{
	//1)update the next ptr of 1st node, make it store the add of 3rd node\
	//2)make the next ptr of second node(which is to be 1st),
	//store the add of 1st node
	//3)update the new head of the list as second node 
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node *stack_a)
{
	t_node	*first;
	t_node	*second;

//store the pointer to the first and 2nd node
	first = stack_a;
	second = stack_a->next;
	swap(&stack_a, first, second);
	ft_putendl_fd("sa", 1);
}

void	sb(t_node *stack_b)
{
	t_node	*first;
	t_node	*second;

	first = stack_b;
	second = stack_b->next;
	swap(&stack_b, first, second);
	ft_putendl_fd("sb", 1);
}

void	ss(t_node *stack_a, t_node *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putendl_fd("ss", 1);
}
