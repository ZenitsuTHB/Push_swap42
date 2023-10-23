/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:18:12 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/23 22:10:23 by avolcy           ###   ########.fr       */
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
	struct node	*prev;
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
//}t_list;

void	ft_error(void);
void	ft_input_arg(int argc, char **argv);
#endif
