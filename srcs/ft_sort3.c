/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:51:12 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/07 21:04:17 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_node *stack)
{
	while (stack)
    {
        printf("this is node[%i] -> %d\n", stack->index, stack->num);
        stack = stack->next;
    }
}
//to structure 
//instead of using stacka->size, call directly the function that 
//calcutes the size
static	void	ft_sort2(t_node **stack)
{
		if (ft_stacksize(*stack) == 2 && ft_is_sorted(*stack) == 1)
		{
			printf("\nnumber is 2\n");
			sa(stack);
			print_stack(*stack);
		}
		else
			exit(0);
		ft_clearnodes(stack);	
}

void	ft_sort3(t_node **stack, int if_5)
{
	int 	num1;
	int 	num2;
	int 	num3;

	if (ft_stacksize(*stack) <= 2)
		ft_sort2(stack);
	else if (ft_stacksize(*stack) == 3 && ft_is_sorted(*stack) == 1)
	{
		num1 = (*stack)->num;
		num2 = (*stack)->next->num;
		num3 = (*stack)->next->next->num;
		if(num1 > num2 && num1 < num3 && num2 < num3)
			sa(stack);
		else if(num1 < num2 && num1 > num3)// && num3 < num1)
			rra(stack);
		else if(num1 < num2 && num1 < num3)// && num3 < num1)
		{	
			sa(stack);
			ra(stack);
		}
		else if(num1 > num2 && num1 > num3 && num2 < num3)
			ra(stack);
		else //(num1 > num2 && num1 > num3 && num2 > num3)
		{
			ra(stack);
			sa(stack);
		}
		if (if_5 == 1)
			ft_clearnodes(stack);
	}
}
