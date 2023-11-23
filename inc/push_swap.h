/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:18:12 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/22 21:12:26 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_move
{
	int			ra;
	int			rb;
//	int			rr;
	int			rra;
	int			rrb;
//	int			rrr;
	int			cost;
}t_move;

typedef struct	s_node
{
	int			num;
	int			index;
//	t_move		*moves;
	struct s_node	*next;
}t_node;

//
/***********************************/
/*  to delete after organize       */
void	print_stack(t_node *stack);//
/***********************************/

//======|  MOVES  |======/

//_______| _PUSH_ |___________________/
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
//_____________________________________________/

//_______| _SWAP_ |___________________/
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
//_____________________________________________/

//_______| _ROTATE_ |___________________/
void	ra(t_node **stack_a);
void	rb(t_node **stack_a);
void	rr(t_node **stack_a, t_node **stack_b);
//_____________________________________________/

//_______| _REVERSE_ROTATE_ |___________________/
void	rra(t_node **stack_a);
void	rrb(t_node **stack_a);
void	rrr(t_node **stack_a, t_node **stack_b);
//==========================================/

//==========| _ALGORITHMS_ |==================/
void	ft_sort3(t_node **stack, int if_5);
void	ft_sort5(t_node **stacka);//, t_node **stackb);
int	ft_bigsort2(t_node **stacka);//, t_node **stackb);
void	ft_error(void);
int		ft_is_sorted(t_node *stack);
void	ft_clearnodes(t_node **stack);
void	ft_clear_arg(char ***stack, int i);
int		ft_stacksize(t_node *lst);
void	ft_input_arg(int argc, char **argv);
void	ft_index(t_node *stack);
void	ft_put_min_top(t_node **stack);
#endif
