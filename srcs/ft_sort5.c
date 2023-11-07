/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:48 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/07 17:29:04 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort5(t_node **stacka)
{
	int		count;
	t_node *stackb;

	count = 0;
	stackb = NULL;
	if (ft_stacksize(*stacka) == 4)
		count = 1;
	while (stacka && count < 2)
	{
		ft_put_max_top(stacka);
		pb(stacka, &stackb);
		print_stack(stackb);
		printf("staka after pushing to b\n");
		print_stack(*stacka);
		count++;
	}
	ft_sort3(stacka, 0);
	printf("\n\n=======stack_a after sort3=======\n");
	print_stack(*stacka);
	while (stackb)
			pa(stacka, &stackb);
	printf("stack a after pushing a\n");
	print_stack(*stacka);
	ft_clearnodes(stacka);// comment because stacka is freed in sort3;
	ft_clearnodes(&stackb);
}
//look for the biggest num and past it to b
//look for the second biggest num and past it to b
//call the sort3 algo to sort the 3 left and "pusha, rra" twice 
