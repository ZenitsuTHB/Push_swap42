/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:18:12 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/01 20:22:20 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "../libft/libft.h"

# define ARG_MSG "Please, try some good arguments now🙄🥱\n"
# define SIGN_MSG "🤨Why did you put a sign in middle or at end🙄🙄\n"
# define CHAR_MSG "Characters found👊😡! push_swap can't be processed🥵\n" 
# define INT_PROB "Your input has number bigger or smaller than integer🤓🤓\n"
# define DUP_MSG "It seems like you have duplicated number🧐, try again🤪\n"

typedef struct	node 
{
	int			num;
	int			size;
	int			index;
//	struct node	*prev;
	struct node	*next;
}t_node;

//typedef struct s_stack
//{ 
//	struct *node top_a;
//	struct *node top_b;
//}t_stack;
//
//typedef struct s_list
//{
//	void			*content;
//	struct s_list	*next;
//}t_node;

//======|  MOVES  |======/

//_______| _PUSH_ |___________________/
void	pa(t_node **stack_a, int data);
void	pb(t_node **stack_a, int data);
//_____________________________________________/

//_______| _SWAP_ |___________________/
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
//_____________________________________________/

//_______| _ROTATE_ |___________________/
void    ra(t_node **stack_a);
void    rb(t_node **stack_a);
void    rr(t_node **stack_a, t_node **stack_b);
//_____________________________________________/


//_______| _REVERSE_ROTATE_ |___________________/
void    rra(t_node **stack_a);
void    rrb(t_node **stack_a);
void    rrr(t_node **stack_a, t_node **stack_b);
//==========================================/

//==========| _ALGORITHMS_ |==================/
void    ft_sort3(t_node *stack);
void	ft_error(void);
int		ft_is_sorted(t_node *stack);
void    ft_clearnodes(t_node **stack);
void    ft_clear_arg(char ***stack, int i);
int     ft_nodesize(t_node *lst); 
void	ft_input_arg(int argc, char **argv);
void	ft_index(t_node *stack);

#endif
