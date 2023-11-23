/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigsort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:57:20 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/23 22:09:33 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//Mira en un stack sin moverlo, si la pieza con index X que busco
//esta en la parte alta o baja del stack, si esta en parte alta devuelve 1
//sino devuelve 2
//int best_direction(int index, t_node **stack)
//{
//	
//	return(1);
//}
//
//void put_nbr_in_top(int index, t_node **stack)
//{
//	int dir;
//
//	dir = best_direction(index, stack);
//	while(/*El indice que quiero este en el top del stack*/)
//	{
//		if(dir == 1)
//			rb();
//		else
//			rrb();
//	}
//}
static int find_max_pos(t_node *stack)
{
	int pos;
	int num;
	int cur_pos;

	cur_pos = 0;
	num = stack->num;
	while (stack)
	{
		if (stack->num > num)
		{
			pos = cur_pos;
			num = stack->num;
		}
		cur_pos++;
		stack = stack->next;
	}
	return (pos);
}

void	ft_put_max_top(t_node **stack)
{
	int		position;
	int		way_up;
	int		way_down;
	int		stack_len;

	position = find_max_pos(*stack);
	stack_len = ft_stacksize(*stack);
	way_up = position;
	way_down = stack_len - position;
	if (way_up <= way_down)
	{
		while (way_up > 0)
		{
			rb(stack);
			way_up--;
		}
	}
	else if (way_down < way_up)
	{
		while (way_down > 0)
		{
			rrb(stack);
			way_down--;
		}
	}
}
//static void move_to_chunks(int num_chunks, t_node **a, t_node **b) {
//    int chunk_len;
//    int total_pieces;
//    
//    total_pieces = ft_stacksize(*a);
//    chunk_len = total_pieces / num_chunks;
//
//    while (num_chunks) {
//        int count = 0;
//        while (count < chunk_len && ft_stacksize(*a) > 0) {
//            if ((*a)->index <= (chunk_len * num_chunks) && (*a)->index > (chunk_len * (num_chunks - 1))) {
//                pb(a, b);
//                count++;
//            } else {
//                ra(a);
//            }
//        }
//        num_chunks--;
//    }
//}

static	void	move_to_chunks(int num_chunks, t_node **a, t_node **b)
{
	int count;
	int limit;
	int chunk_len;
	int total_pieces;

	total_pieces = ft_stacksize(*a);
	chunk_len = total_pieces / num_chunks;
	count = chunk_len;
	limit = chunk_len;
	while(num_chunks)
	{
		while(count)
		{
			if((*a)->index <= limit)
			{
				pb(a, b);
				if ((*b)->index < (limit - (chunk_len / 2)) && (*b)->next)
				 	rb(b);
				count--;
			}
			else
				ra(a);
		}
		limit = limit + chunk_len;
		count = chunk_len;
		num_chunks--;
	}
}

static	int	find_num_chunks(t_node *stack)
{
	int num_chunks;
	int	total_pieces;
	
	num_chunks = 0;
	total_pieces = ft_stacksize(stack);
	if (total_pieces <= 100)
		num_chunks = 5;
	else if (total_pieces <= 500)
		num_chunks = 8 ;
	return (num_chunks);
}

int ft_bigsort2(t_node **a)
{
	t_node *b;
	int total;
	int		num_chunks;

	b = NULL;
	total = ft_stacksize(*a);
	num_chunks = find_num_chunks(*a);
	move_to_chunks(num_chunks, a, &b);
	while(ft_stacksize(*a)) //por si acaso la division de chunks a  dejado una pieza perdida en a
		pb(a, &b);
	while(total)
	{
		ft_put_max_top(&b);
		//put_nbr_in_top(total, &b);
		pa(a, &b);
		total--;
		
	}
//	print_stack(*a);
//	printf("\n=========stack_b=========\n");
//	print_stack(b);
	ft_clearnodes(&b);
	ft_clearnodes(a);
	return (1);
}
