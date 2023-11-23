/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:09:12 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/21 17:19:53 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//how to divide by chunks ?
//if size is bigger than 100, 8 chunks
//100 / 5 = 20 num per chunks
//500 / 8 = 62 num per chunks
//if size > 100
//           donnees
//         1) stack
//         2) stack->index;
//         3) curs	pu	s
//static	t_node	*find_mid_node(t_node *aux, int mid_pos)
//{
//	int	pos;
//	t_node *cur;
//
//	pos = 0;
//	while (pos < mid_pos)
//	{
//		cur = aux;
//		aux = aux->next;
//		pos++;
//	}
//	return (cur);
//}

//static	int check_last_node(t_node *aux, int mid)
//{
//	t_node	*a = aux;
//	while (a->next)
//		a = a->next;
//	if (a->index < mid)
//		return (1);
//	return (0);
//}
//static	int	find_min_pos(t_node *stack)
//{
//	int		pos;
//	int		num;
//	int		cur_pos;
//
//	cur_pos = 0;
//	num = stack->num;
//	while (stack)
//	{
//		if (stack->num < num)
//		{
//			pos = cur_pos;
//			num = stack->num;
//		}
//		cur_pos++;
//		stack = stack->next;
//	}
//	return (pos);
//}

//void	ft_put_min_top(t_node **stack, int median)
//{
//	int		position;
//	int		way_up;
//	int		way_down;
//	int		stack_len;
//
//	position = find_min_pos(*stack);
//	stack_len = ft_stacksize(*stack);
//	way_up = position;
//	way_down = stack_len - position;
//	if (way_up <= way_down)
//	{
//		while (way_up > 0)
//		{
//			ra(stack);
//			way_up--;
//		}
//	}
//	else if (way_down < way_up)
//	{
//		while (way_down > 0)
//		{
//			rra(stack);
//			way_down--;
//		}
//	}
//}

static int  find_max_idx(t_node *stack)
{
	int num;

	num = stack->index;
	while (stack)
	{
		if (stack->index > num)
			num = stack->index;
		stack = stack->next;
	}
	return (num);
}

//static	int its_below_median(t_node *a, int median)
//{
//	int flag;
//
//
//	flag = 0;
//	if ((*a).index < median)
//		flag = 1;
//	return (flag);
//}

void    ft_bigsort(t_node **a)
{
	int	median;
	int	size;
	t_node	*b;
	t_node	*aux;
	aux	= *a;
	int		*array;

	b = NULL;
	int i = 0;
	median = find_max_idx(*a) / 2;
	size = ft_stacksize(*a);
	array = (int *)malloc(sizeof(int) * size);
	while ((aux != NULL && i < size))
	{
		array[i++] = (aux)->num;
		aux = aux->next;
//		ft_put_min_top(a, median);
	//	if (its_below_median(*a, median) == 1)
	//		pb(a, &b);
	//	ra(a);
		//size = ft_stacksize(*a);
		//median = find_max_idx(*a) / 2;
	}
	median = i / 2;
	printf("Elements copied to the array:\n");
    for (int j = 0; j < i; j++) {
        printf("%d ", array[j]);
    }
    printf("\nmedian %d ", median);
    printf("\n");
}
//static t_node *find_mid_node(t_node *stack) {
//    if (!stack || !stack->next) {
//        // Stack is empty or has only one element
//        return stack;
//    }
//
//    t_node *slow = stack;
//    t_node *fast = stack;
//
//    while (fast->next && fast->next->next) {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//
//    return slow;
//}
