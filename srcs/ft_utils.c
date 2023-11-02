/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:23:06 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/01 20:50:46 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_index(t_node *stack)
{
	int		idx;
	t_node *head;
	t_node *iterator;

	head = stack;
	iterator = stack;
	idx = 1;
	while (head)
	{
		idx = 1;
		iterator = stack;
		while (iterator)
		{
			if(iterator->num < head->num)
				idx++;
			iterator = iterator->next;
		}
		head->index = idx;
		head = head->next;
	}

}
