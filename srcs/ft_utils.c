/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:23:06 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/07 16:20:49 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_index(t_node *stack)
{
	int		idx;
	t_node *head;
	t_node *iterator;

	idx = 1;
	head = stack;
	while (head)
	{
		idx = 1;
		iterator = stack;
		while (iterator)
		{
			if(iterator->num < head->num)
				idx++;
			iterator = iterator->next;
		}
		head->index = idx;
		head = head->next;
	}

}

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
//	return (pos);
//}
static int find_min_pos(t_node *stack)
{
	int pos;
	int num;
	int cur_pos;

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
	printf("min is %d\n",pos);
	return (pos);
}

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

void    ft_put_max_top(t_node **stack)
{
	int position;
    int way_up;
    int way_down;
    int stack_len;
  //  int max_node;

	position = find_min_pos(*stack);
    printf("position -> %d\n", position);
	stack_len = ft_stacksize(*stack);
//    max_node = find_max_node(*stack);
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
			printf("stack after bottom op\n");
			print_stack(*stack);
        }
    }
}
