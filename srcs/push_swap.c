/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:15:53 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/30 21:07:51 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*==================FILL_STACK_CREATE_NODES====================*/
t_node	*ft_fillstack(int argc, char **argv, t_node *stack)
{
	int		i;
	t_node	*head;
	char	**avsp;

	i = 1;
	if (argc == 2)
	{
		i = 0;
		avsp = ft_split(argv[1], ' ');
		if(!avsp)
			return NULL;
		argv = avsp;
	}
	stack = (t_node *)malloc(sizeof(t_node));
	if (!stack)
		ft_clearnodes(&stack);
	stack->next = NULL;
	head = stack;
	while (argv[i])
	{
		stack->num = ft_atoi(argv[i]);
		printf("this is the node [%d] --> %d\n", i, stack->num);
		if (argv[i + 1])
			stack->next = (t_node*)malloc(sizeof(t_node));
		// El ultimo caso no se guardara bien!!!!! argv[i + 1] .....
		else
			stack->next = NULL;
		stack = stack->next;
		i++;
	}
	if (argc == 2)
		ft_clear_arg(&avsp, 0);
	return (head);
}
/*------------------------------------------------------------*/

/*=================PUSH_SWAP_MAIN=============================*/
int	main(int argc, char **argv)
{
	t_node *stack_a;

	stack_a = NULL;
	ft_input_arg(argc, argv);
	stack_a = ft_fillstack(argc, argv, stack_a);
	printf("%d\n", ft_is_sorted(stack_a));
	//while (stack_a->next != NULL)
	//{
	//	printf("%d\n", stack_a->num);
	//	stack_a = stack_a->next; 
	//}
	if(ft_is_sorted(stack_a) == 0)
	{
		printf("is sorted bro\n");
	}
	else 
	{
		printf("is not sorted bro\n"); 
	}
	ft_clearnodes(&stack_a);
	return (0);
}
/*------------------------------------------------------------*/
