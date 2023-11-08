/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:15:53 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/08 17:37:34 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*=====| _LSTSIZE_ |=========*/
int	ft_stacksize(t_node *lst)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = lst;
	if (!tmp)
		return (count);
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count++);
}
/*==========================*/

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
		if (!avsp)
			return (NULL);
		argv = avsp;
	}
	stack = (t_node *)malloc(sizeof(t_node));
	if (!stack)
		ft_clearnodes(&stack);
	stack->next = (NULL);
	head = stack;
	while (argv[i])
	{
		stack->num = ft_atoi(argv[i]);
		if (argv[i + 1])
			stack->next = (t_node *)malloc(sizeof(t_node));
		else
			stack->next = (NULL);
		stack = stack->next;
		i++;
	}
	if (argc == 2)
		ft_clear_arg(&avsp, 0);
	return (head);
}
/*------------------------------------------------------------*/

void	print_stack(t_node *stack);

/*=================PUSH_SWAP_MAIN=============================*/
int	main(int argc, char **argv)
{
	t_node	*stack_a;

	stack_a = NULL;
	ft_input_arg(argc, argv);
	stack_a = ft_fillstack(argc, argv, stack_a);
	ft_index(stack_a);
	printf("\n\nsize stak_a -> %d\n", ft_stacksize(stack_a));
	printf("stak_a before operation\n");
	print_stack(stack_a);
	if (ft_is_sorted(stack_a) == 0)
		ft_clearnodes(&stack_a);
	else if (ft_stacksize(stack_a) <= 3)
	{
		printf("Stack isn't sorted bro, size less or = to 3, sort3\n");
		ft_sort3(&stack_a, 1);
	}
	else if (ft_stacksize(stack_a) > 3 && ft_stacksize(stack_a) <= 5)
	{
		printf("Stack isn't sorted bro, size less or = to 5, sort5\n");
		ft_sort5(&stack_a);
	}
	return (0);
}
/*------------------------------------------------------------*/
