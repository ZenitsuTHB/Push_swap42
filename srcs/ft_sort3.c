/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:51:12 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/01 20:48:39 by avolcy           ###   ########.fr       */
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
void	ft_sort3(t_node *stack)
{
	int 	num1;
	int 	num2;
	int 	num3;

	num1 = stack->num;
	num2 = stack->next->num;
	num3 = stack->next->next->num;
	if(num1 > num2 && num2 < num3 && num3 > num1)
	{
		printf("second case\nnum1 > num2 && num2 < num3 && num3 > num1\n");
		sa(&stack);
		print_stack(stack);
	}
	else if(num1 < num2 && num2 > num3)
	{
		printf("third case\nnum1 < num2 && num2 > num3\n");
		rra(&stack);
		print_stack(stack);
	}
	else if(num1 > num2 && num2 > num3)
	{
		printf("4th case\nnum1 > num2 && num2 > num3\n");
		sa(&stack);
		print_stack(stack);
		rra(&stack);
		print_stack(stack);
	//	ft_clearnodes(&stack);
	}
	else if(num1 > num2 && num2 < num3 && num3 < num1)
	{
		printf("5th case\nnum1 > num2 && num2 < num3 && num3 < num1\n");
		ra(&stack);
		print_stack(stack);
	}
	else
		printf("bigger algo bro\n");
	stack->size--;
	ft_clearnodes(&stack);
}
