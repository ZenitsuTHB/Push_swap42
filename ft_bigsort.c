/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:32:09 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/22 20:56:19 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//========| STEPS |=========//
//1) 2 pushes to the stack b
////2)
//
//static	void	execute_best_moves(t_node **a, t_node **b, t_move best)
//{
//	while(best.ra-- != 0)
//		ra(a);
//	while(best.rb-- != 0)
//		rb(b);
//	while(best.rra-- != 0)
//		rra(a);
//	while(best.rrb-- != 0)
//		rrb(a);
//}

static int  find_max_idx(t_node *stack)
{
	int postmp;
	int pos;
    int num;

	pos = 0;
	postmp = 0;
    num = stack->num;
    while (stack)
    {
        if (stack->num > num)
		{
			pos = postmp;
            num = stack->num;
		}
        stack = stack->next;
		postmp++;
    }
    return (num);
}
//
////static	void  ft_put_max_top(t_node stack, t_move)
////{
////  int     position;
////  int     way_up;
////  int     way_down;
////  int     stack_len;
////
////  position = find_min_pos(*stack);
////  stack_len = ft_stacksize(*stack);
////  way_up = position;
////  way_down = stack_len - position;
////  if (way_up <= way_down)
////  {
////      while (way_up > 0)
////		  way_up--;
////  }
////  else if (way_down < way_up)
////  {
////      while (way_down > 0)
////          way_down--;
////  }
////}
//
static	void	init_cheap(t_move *init)
{
	init->ra = 0;
	init->rb = 0;
//	init->rr = 0;
	init->rra = 0;
	init->rrb = 0;
//	init->rrr = 0;
	init->cost = 0;
}

static	t_move	find_cheapest_cost(t_node *a, t_node *b)
{
	t_move	cheap;
	int		biggestb;
//	int		smallestb;

	init_cheap(&cheap);
	biggestb = find_max_idx(b);
	while (a)
	{
		if (a->num > biggestb && biggestb == b->num)
		{
			cheap.cost = 0;
			return (cheap);
		}
		//else if ()
		//	cheap = find_cost_pos;ft_put_max_top(b, cheap);
		a = a->next;
	}
	//cheap.cost = cheap.ra + cheap.rb + cheap.rra + cheap.rrb;
	return (cheap);
}

static	t_move	find_best_moves(t_node *a, t_node *b)
{
	t_move 	best;
	t_move  best_tmp;

	best = find_cheapest_cost(a, b);
	a = a->next;
	while (a)
	{
		best_tmp = find_cheapest_cost(a, b);
		if (best.cost > best_tmp.cost)
			best = best_tmp;
		a = a->next;
	}
	return (best);
}

void	ft_bigsort(t_node **a)
{
	int size;
	t_node *b;
	t_move best;

	b = NULL;
	pb(a, &b);
	pb(a, &b);
	size = ft_stacksize(*a);
	while (size > 3)
	{
		best = find_best_moves(*a, b);
		//best.cost = 0;
		printf("best_cost-> %d\n", best.cost);
		if (best.cost == 0)
			pb(a, &b);
		//else
		//{
		//	execute_best_moves(a, &b, best);
		//	pb(a, &b);
		//}
		//*a = (*a)->next;
		size--;
		size = ft_stacksize(*a);
	}
	printf("\n=====| stack a |======\n");
	print_stack(*a);
	printf("\n=====| stack b |======\n");
	print_stack(b);
//	ft_clearnodes(&b);
}
////========| STEPS |=========//
////1) 2 pushes to the stack b
////2) 
//
//static	void	execute_best_moves(t_node **a, t_node **b, t_move best)
//{
//	while(best.ra-- != 0)
//		ra(a);
//	while(best.rb-- != 0)
//		rb(b);
//	while(best.rra-- != 0)
//		rra(a);
//	while(best.rrb-- != 0)
//		rrb(a);
//}
//
//static int  find_max_idx(t_node *stack)
//{
//    int num;
//
//    num = stack->num;
//    while (stack)
//    {
//        if (stack->num > num)
//            num = stack->num;
//        stack = stack->next;
//    }
//    return (num);
//}
//
////static	void  ft_put_max_top(t_node stack, t_move)
////{
////  int     position;
////  int     way_up;
////  int     way_down;
////  int     stack_len;
////
////  position = find_min_pos(*stack);
////  stack_len = ft_stacksize(*stack);
////  way_up = position;
////  way_down = stack_len - position;
////  if (way_up <= way_down)
////  {
////      while (way_up > 0)
////		  way_up--;
////  }
////  else if (way_down < way_up)
////  {
////      while (way_down > 0)
////          way_down--;
////  }
////}
//
//static	void	init_cheap(t_move *init)
//{
//	init->ra = 0;
//	init->rb = 0;
////	init->rr = 0;
//	init->rra = 0;
//	init->rrb = 0;
////	init->rrr = 0;
//	init->cost = 0;
//}
//
//static	t_move	find_cheapest_cost(t_node *a, t_node *b)
//{
//	t_move	cheap;
//	int		biggestb;
//	
//	init_cheap(&cheap);
//	biggestb = find_max_idx(b);	
//	while (a)
//	{
//		if (a->num > biggestb && biggestb == b->num)
//			cheap.cost = 0;
//		else
////			cheap = ft_put_max_top(b, cheap);	
//		a = a->next;
//	}
//	cheap.cost = cheap.ra + cheap.rb + cheap.rra + cheap.rrb;
//	return (cheap);
//}
//
//static	t_move	find_best_moves(t_node *a, t_node *b)
//{
//	t_move 	best;
//	t_move  best_tmp;
//
//	best = find_cheapest_cost(a, b);
//	while (a)
//	{
//		best_tmp = find_cheapest_cost(a, b);  
//		if (best.cost > best_tmp.cost)
//			best = best_tmp;
//		a = a->next;
//	}
//	return (best);
//}
//
//void	ft_bigsort(t_node **a)
//{
//	t_node *b;
//	t_move best;
//
//	b = NULL;
//	pb(a, &b);
//	pb(a, &b);
//	while (*a)
//	{
//		best = find_best_moves(*a, b);
//		if (best.cost == 0)
//			pb(a, &b);
//		else
//		{
//			execute_best_moves(a, &b, best);
//			pb(a, &b);
//		}
//		*a = (*a)->next;
//	}
//	printf("\n=====| stack a |======\n");
//	print_stack(*a);
//	printf("\n=====| stack b |======\n");
//	print_stack(b);
////	ft_clearnodes(&b);
//}
