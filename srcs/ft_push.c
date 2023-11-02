/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:19 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/02 21:31:20 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	void push(t_node **stacka, t_node **stackb)
{
	//t_node	*new_a;
	t_node	*tmp_a;
	
	tmp_a = (*stacka)->next;
	stackb = stacka;
	//(*stackb)->next = NULL;
	(*stacka)->next = NULL;
	//stackb = stacka;
	 *stacka = tmp_a;
//	//allocate for new node
//	//put in data
//	//make next of new as head, my case stack
//	//move head to point to new as new head of list;
//	new = (t_node *)malloc(sizeof(t_node));
//	if (new)
//	{
//		new->num = data;
//		new->next = *(*stack);
//		*(*stack) = new;
//	}
////	ft_clearnodes(&new);
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
