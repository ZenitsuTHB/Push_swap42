/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:19 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/03 13:35:19 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	void push(t_node **stacka, t_node **stackb)
{
	t_node	*tmp_b;
	
	if (stacka)
	{
		tmp_b = *stacka;
		(*stacka) = (*stacka)->next;
		tmp_b->next = *stackb;
		(*stackb) = tmp_b;
	}
}

void	pa(t_node **stacka, t_node **stackb)
{
	push(stacka, stackb);
	ft_putendl_fd("pa", 1);
}

void	pb(t_node **stacka, t_node **stackb)
{
	push(stacka, stackb);
	ft_putendl_fd("pb", 1);
}
