/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:51:12 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/03 19:45:59 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_node *stack)
{
	while(stack)
    {

        printf("this is node[%i] -> %d\n", stack->index, stack->num);
        stack = stack->next;
    }
}
//to structure 
//instead of using stacka->size, call directly the function that 
//calcutes the size
void	ft_sort3(t_node **stack, int if_5)
{
	int 	num1;
	int 	num2;
	int 	num3;

	if (ft_nodesize(*stack) <= 2)
	{
		if (ft_nodesize(*stack) == 2 && ft_is_sorted(*stack) == 1)
		{
			printf("\nnumber is 2\n");
			sa(stack);
			print_stack(*stack);
		}
		else
			exit(0);
		ft_clearnodes(stack);
	}
	else if (ft_nodesize(*stack) == 3)
	{
		num1 = (*stack)->num;
		num2 = (*stack)->next->num;
		num3 = (*stack)->next->next->num;
		if(num1 > num2 && num1 < num3 && num2 < num3)
		{
			printf("second case\nnum1 > num2 && num2 < num3 && num3 > num1\n");
			sa(stack);
			print_stack(*stack);
		}
		else if(num1 < num2 && num1 > num3)// && num3 < num1)
		{
			printf("third case\nnum1 < num2 && num2 > num3\n");
			rra(stack);
			print_stack(*stack);
		//	sa(stack);
		//	print_stack(stack);
		}
		else if(num1 < num2 && num1 < num3)// && num3 < num1)
		{
			printf("4th case\nnum1 > num2 && num2 > num3\n");
			sa(stack);
			print_stack(*stack);
			ra(stack);
			print_stack(*stack);
		//	ft_clearnodes(stack);
		}
		else if(num1 > num2 && num1 > num3 && num2 < num3)
		{
			printf("5th case\nnum1 > num2 && num2 < num3 && num3 < num1\n");
			ra(stack);
			print_stack(*stack);
		}
		else //(num1 > num2 && num1 > num3 && num2 > num3)
		{
			printf("6th case\nnum1 > num2 && num1 > num3 && num2 > num3\n");
			ra(stack);
			print_stack(*stack);
			sa(stack);
			print_stack(*stack);
		}
		if (if_5 == 1)
			ft_clearnodes(stack);
	}
}
