/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:32:09 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/19 21:39:21 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//========| STEPS |=========//
//1) 2 pushes to the stack b
//2) 

static	void	execute_best_moves(t_node **a, t_node **b, t_move best)
{
}

static int  find_min_idx(t_node *stack)
{
    int num;

    num = stack->index;
    while (stack)
    {
        if (stack->index < num)
            num = stack->index;
        stack = stack->next;
    }
    return (num);
}

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

 static	t_move	*find_cheapest_cost(t_node a, t_node b)
{
	t_move	cheapest;
	int		biggestb;
	int		smallestb;

	biggestb = find_max_idx(b);	
	smallestb = find_min_idx(b);
	while (a)
	{
			while (b)
			{
				if (a->index > b->index)
				b = b->next;
			}
		a = a->next;
	}
	return (cheapest);
}

static	t_moves	find_best_moves(t_node *a, t_node *b)
{
	t_move 	best;
	t_move  best_tmp;

	best = find_cheapest_cost(a, b);
	while (a)
	{
		best_tmp = find_cheapest_cost(a, b);  
		if (best.cost > best_tmp.cost)
			best = best_tmp;
		a = a.next;
	}
	return (best);
}

void	ft_bigsort(t_node **a)
{
	t_node *b;
	t_move best;

	b = NULL;
	pb(a, &b);
	pb(a, &b);
	while (*a)
	{
		best = find_best_moves(*a, b);
		execute_best_moves(a, &b, best);
		(*a) = (*a)->next;
	}
	printf("\n=====| stack a |======\n");
	print_stack(*a);
	printf("\n=====| stack b |======\n");
	print_stack(b);
//	ft_clearnodes(&b);
}
