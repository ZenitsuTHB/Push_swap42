/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:19 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/07 20:40:05 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	void	push(t_node **stack1, t_node **stack2)
{
	t_node	*tmp_2;

	if (stack1)
	{
		tmp_2 = *stack1;
		(*stack1) = (*stack1)->next;
		tmp_2->next = *stack2;
		(*stack2) = tmp_2;
	}
}

void	pa(t_node **stacka, t_node **stackb)
{
	push(stackb, stacka);
	ft_putendl_fd("pa", 1);
}

void	pb(t_node **stacka, t_node **stackb)
{
	push(stacka, stackb);
	ft_putendl_fd("pb", 1);
}
