/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:48 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/02 21:29:36 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort5(t_node *stacka)
{
	t_node *stackb;

	stackb = NULL;
	while (stacka->size > 3)
	{
		pb(&stacka, &stackb);
		printf("=======stack_b========\n");
		print_stack(stackb);
		printf("\n\n=======stack_a========\n");
		print_stack(stacka);
		stacka->size--;
	}
//	print_stack(stacka);
	ft_clearnodes(&stacka);
	ft_clearnodes(&stackb);
}
