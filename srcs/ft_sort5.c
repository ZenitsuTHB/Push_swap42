/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:48 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/03 19:44:33 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	void	find_biggest()
{
} 

void	ft_sort5(t_node *stacka)
{
	int		count;
	t_node *stackb;

	printf("stacka->size before loop %d\n", ft_nodesize(stacka));
	count = 0;
	stackb = NULL;
	while (stacka && count < 2)
	{
		printf("\nstacka->size now is %d\n", ft_nodesize(stacka));
		pb(&stacka, &stackb);
		printf("=======stack_b========\n");
		print_stack(stackb);
	//	printf("\n\n=======stack_a========\n");
	//	print_stack(stacka);
		count++;
		//stacka->size--;
	}
	printf("\n\n=======stack_a after loop========\n");
	//stacka->size = 3;//manualmente pero tengo que encontrar forma de decrementar
	//stacka->size;
	ft_sort3(&stacka, 0);
	//printf("\nstacka->size now is %d\n", stacka->size);
	printf("\n\n=======stack_a after sort3=======\n");
	print_stack(stacka);
	ft_clearnodes(&stacka);// comment because stacka is freed in sort3;
	ft_clearnodes(&stackb);
}
//look for the biggest num and past it to b
//look for the second biggest num and past it to b
//call the sort3 algo to sort the 3 left and "pusha, rra" twice 
