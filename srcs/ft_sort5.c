/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:48 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/21 17:19:59 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort5(t_node **stacka)
{
	int		flag;
	int		count;
	t_node	*stackb;

	flag = 0;
	count = 0;
	stackb = NULL;
	if (ft_stacksize(*stacka) == 4)
		count = 1;
	while (stacka && count < 2)
	{
		ft_put_min_top(stacka);
		pb(stacka, &stackb);
		count++;
	}
	ft_sort3(stacka, flag);
	while (stackb)
		pa(stacka, &stackb);
	ft_clearnodes(stacka);
	ft_clearnodes(&stackb);
}
//look for the biggest num and past it to b
//look for the second biggest num and past it to b
//call the sort3 algo to sort the 3 left and "pusha, rra" twice 
