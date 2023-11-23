/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:46:23 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/07 19:30:39 by avolcy           ###   ########.fr       */
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
void	ft_clear_arg(char ***avsp, int i)
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
void	ft_clearnodes(t_node **stack)
{
	t_node	*ptr;

	while (*stack != NULL)
	{
		ptr = *stack;
		*stack = ptr->next;
		free(ptr);
		ptr = NULL;
	}
}

//==========| _IS_SORTED_ |===================/
int	ft_is_sorted(t_node *stack)
{
	int	out;

	out = 0;
	while ((stack)->next && out == 0)
	{
		if ((stack)->num > (stack)->next->num)
			out = 1;
		(stack) = (stack)->next;
	}
	return (out);
}
//=============================================/
