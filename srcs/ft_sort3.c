/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:51:12 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/26 17:09:42 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*=================|_SORT_2_ALGO_|==============================*/
static	void	ft_sort2(t_node **stack)
{
	if (ft_stacksize(*stack) == 2 && ft_is_sorted(*stack) == 1)
		sa(stack);
	else
		exit(0);
	ft_clearnodes(stack);
}
/*----------------------------------------------------------------*/

/*=================|_SORT_3_ALGO_|===========================*/
void	ft_sort3b(t_node **stack, int *n1, int *n2, int *n3);

void	ft_sort3(t_node **stack, int if_5)
{
	int		num1;
	int		num2;
	int		num3;

	if (ft_stacksize(*stack) <= 2)
		ft_sort2(stack);
	else if (ft_stacksize(*stack) == 3)
	{
		num1 = (*stack)->num;
		num2 = (*stack)->next->num;
		num3 = (*stack)->next->next->num;
		ft_sort3b(stack, &num1, &num2, &num3);
		if (if_5 == 1)
			ft_clearnodes(stack);
	}
}
/*----------------------------------------------------------*/

/*===============|_SORT_3B_ALGO_|============================*/
void	ft_sort3b(t_node **stack, int *n1, int *n2, int *n3)
{
	if (ft_is_sorted(*stack) == 1)
	{
		if (*n1 > *n2 && *n1 < *n3 && *n2 < *n3)
			sa(stack);
		else if (*n1 < *n2 && *n1 > *n3)
			rra(stack);
		else if (*n1 < *n2 && *n1 < *n3)
		{
			sa(stack);
			ra(stack);
		}
		else if (*n1 > *n2 && *n1 > *n3 && *n2 < *n3)
			ra(stack);
		else
		{
			ra(stack);
			sa(stack);
		}
	}
}
/*----------------------------------------------------------*/
