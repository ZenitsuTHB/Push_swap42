/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:23:06 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/26 17:09:39 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*=====| _LSTSIZE_ |=========*/
int	ft_stacksize(t_node *lst)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = lst;
	if (!tmp)
		return (count);
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count++);
}
/*___________________________*/

/*======|_FT_INDEX_|==========*/
void	ft_index(t_node *stack)
{
	int		idx;
	t_node	*head;
	t_node	*iterator;

	idx = 1;
	head = stack;
	while (head)
	{
		idx = 1;
		iterator = stack;
		while (iterator)
		{
			if (iterator->num < head->num)
				idx++;
			iterator = iterator->next;
		}
		head->index = idx;
		head = head->next;
	}
}
/*----------------------------------------*/

/*========|_FIND_MIN_POS_|=============*/
static	int	find_min_pos(t_node *stack)
{
	int		pos;
	int		num;
	int		cur_pos;

	cur_pos = 0;
	num = stack->num;
	while (stack)
	{
		if (stack->num < num)
		{
			pos = cur_pos;
			num = stack->num;
		}
		cur_pos++;
		stack = stack->next;
	}
	return (pos);
}
/*---------------------------------------*/

/*========|_PUT_MIN_TOP_|=============*/
void	ft_put_min_top(t_node **stack)
{
	int		position;
	int		way_up;
	int		way_down;
	int		stack_len;

	position = find_min_pos(*stack);
	stack_len = ft_stacksize(*stack);
	way_up = position;
	way_down = stack_len - position;
	if (way_up <= way_down)
	{
		while (way_up > 0)
		{
			ra(stack);
			way_up--;
		}
	}
	else if (way_down < way_up)
	{
		while (way_down > 0)
		{
			rra(stack);
			way_down--;
		}
	}
}
/*--------------------------------------*/
//static int find_max_pos(t_node *stack)
//{
//	int pos;
//	int num;
//	int cur_pos;
//
//	cur_pos = 0;
//	num = stack->num;
//	while (stack)
//	{
//		if (stack->num > num)
//		{
//			pos = cur_pos;
//			num = stack->num;
//		}
//		cur_pos++;
//		stack = stack->next;
//	}
//	return (pos);}
//static int  find_max_node(t_node *stack)
//{
//	int num;
//
//	num = stack->num;
//	while (stack)
//	{
//		if (stack->num > num)
//			num = stack->num;
//		stack = stack->next;
//	}
//	return (num);
//}	
