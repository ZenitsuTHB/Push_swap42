/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:51:12 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/31 22:25:36 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_node *stack)
{
	while(stack)
    {

        printf("this is node[] -> %d\n", stack->num);
        stack = stack->next;
    }
}
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
		printf("second case\n");
		sa(&stack);
		print_stack(stack);
	}
	else if(num1 < num2 && num2 > num3)
	{
		printf("third case\n");
		rra(&stack);
		print_stack(stack);
	}
	else if(num1 > num2 && num2 > num3)
	{
		printf("4th case\n");
		sa(&stack);
		print_stack(stack);
		rra(&stack);
		print_stack(stack);
	}
	else if(num1 > num2 && num2 < num3 && num3 < num1)
	{
		printf("5th case\n");
		ra(&stack);
		print_stack(stack);
	}
	else
		printf("bigger algo bro\n");
	stack->size--;
}
