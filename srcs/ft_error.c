/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:46:23 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/30 21:07:47 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//======| _FT_ERROR_ |========/
void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
//==========================/

//=======| _CLEAN_UP_ARGV_ |==============/
void    ft_clear_arg(char ***avsp, int i)
{
    while ((*avsp)[i])
	{
        free((*avsp)[i]);
		i++;
	}
    free(*avsp);
}
//=======================================/

//========| _CLEAN_UP_STACK_ |==========/
void    ft_clearnodes(t_node **stack)
{
    t_node  *ptr;

    while(*stack != NULL)
    {
        ptr = *stack;
        *stack = ptr->next;
        free(ptr);
    }
}

//==========| _IS_SORTED_ |===================/
int	ft_is_sorted(t_node *stack)
{
	int out;

	out = 0;
	printf("tooop\n");
	while (stack->next && out == 0)
	{
		printf("stack = %d\n", stack->num);
		if(stack->num > stack->next->num)
			out = 1;
		stack = stack->next;
		printf("out=%d\n", out);
	}
	printf("stack = %d\n", stack->num);
	return (out);
}
//=============================================/
