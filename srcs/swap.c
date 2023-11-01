/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:09:54 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/01 19:14:22 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
//62
//3
//1


static void	swap(t_node **stack)//, t_node *first, t_node *second)
{
//	int tmp;
//
//	tmp = (*stack)->num;
//	(*stack)->num = (*stack)->next->num;
//	(*stack)->next->num = tmp;
	t_node	*first;
	t_node	*second;
	
	first = *stack;
	second = (*stack)->next;
	(*stack) = second;
	first->next = second->next;
	second->next = first;
	//ft_clearnodes(&first);
	//second = NULL;
}

void	sa(t_node **stack_a)
{
	//t_node	*first;
	//t_node	*second;

//store the pointer to the first and 2nd node
	//first = stack_a;
	//second = stack_a->next;
	swap(stack_a);//, first, second);
	ft_putendl_fd("sa", 1);
}

void	sb(t_node **stack_b)
{
	//t_node	*first;
//	t_node	*second;

//	first = stack_b;
//	second = stack_b->next;
	swap(stack_b);//, first, second);
	ft_putendl_fd("sb", 1);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putendl_fd("ss", 1);
}
