/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:19 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/27 20:12:55 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_node **stack, int data)
{
	t_node	*new;

	//allocate for new node
	//put in data
	//make next of new as head, my case stack
	//move head to point to new as new head of list;
	new = (t_node *)malloc(sizeof(t_node));
	if (new)
	{
		new->num = data;
		new->next = (*stack);
		*stack = new;
	}
	ft_clearnodes(&new);
}

void	pa(t_node **stack_a, int data)
{
	push(&stack_a, data);
	ft_putendl_fd("pa", 1);
}

void	pb(t_node **stack_b, int data)
{
	push(&stack_b, data);
	ft_putendl_fd("pb", 1);
}
