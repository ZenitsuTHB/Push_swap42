/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:15:53 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/29 21:16:59 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*==================FILL_STACK_CREATE_NODES====================*/
t_node	*ft_fillstack(int argc, char **argv, t_node *stack)
{
	int		i;
	t_node	*aux;
	char	**avsp;

	i = 1;
	if (argc == 2)
	{
		i = 0;
		avsp = ft_split(argv[1], ' ');
		argv = avsp;
	}
//	ft_clear_arg(&avsp, 0);
	stack = (t_node *)malloc(sizeof(t_node));
	if (!stack)
		ft_clearnodes(&stack);
	aux = stack;
	while (argv[i])
	{
		stack->num = ft_atoi(argv[i]);
		printf("this is the node [%d] --> %d\n", i, stack->num);
		stack->next = (t_node*)malloc(sizeof(t_node));
		// El ultimo caso no se guardara bien!!!!! argv[i + 1] .....
		stack->next->next = NULL;
		if (!stack->next)
			ft_clearnodes(&aux);
		stack = stack->next;
		i++;
	}
	return (aux);
}
/*------------------------------------------------------------*/

/*=================PUSH_SWAP_MAIN=============================*/
int	main(int argc, char **argv)
{
	t_node *stack_a;

	stack_a = NULL;
	ft_input_arg(argc, argv);
	stack_a = ft_fillstack(argc, argv, stack_a);
	if(ft_is_sorted(&stack_a))
	{
		printf("is not sorted bro\n");
	}
	else
		printf("is sorted bro\n");
	ft_clearnodes(&stack_a);
//	ft_clear_arg(&argv, 0);
	return (0);
}
/*------------------------------------------------------------*/
