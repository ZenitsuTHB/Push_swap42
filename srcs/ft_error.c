/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:46:23 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/29 21:17:36 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//=======| _FT_ERROR_ |===============/
void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
//==========================/

//========| _CLEAN_UP_ARGV_ |===============/
void    ft_clear_arg(char ***avsp, int i)
{
    while (avsp[i])
        free(avsp[i]);
    free(avsp);
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
//===================================/

int	ft_is_sorted(t_node **stack)
{
	t_node *current;

	current = (*stack);
	while (current->next != NULL)
	{
		if(current->num < current->next->num)
			return(0);
		current = current->next;
	}
	return (1);
}
