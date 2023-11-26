/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:15:53 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/26 17:00:31 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*=========|_SPLITTING_ARG_|============*/
static char	**splitting_arg(char **argv)
{
	char	**avsp;

	avsp = ft_split(argv[1], ' ');
	if (!avsp)
		return (NULL);
	return (avsp);
}

static t_node	*init_stack(t_node **stack)
{
	*stack = (t_node *)malloc(sizeof(t_node));
	if (!*stack)
		ft_clearnodes(stack);
	(*stack)->next = (NULL);
	return (*stack);
}
/*___________________________________________*/

/*============|_FILL_STACK_CREATE_NODES_|=================*/
t_node	*ft_fillstack(int argc, char **argv, t_node *stack)
{
	int		i;
	t_node	*head;

	i = 1;
	if (argc == 2)
	{
		i = 0;
		argv = splitting_arg(argv);
	}
	stack = init_stack(&stack);
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
		ft_clear_arg(&argv, 0);
	return (head);
}
/*----------------------------------------------------------*/

/*=================PUSH_SWAP_MAIN=============================*/
int	main(int argc, char **argv)
{
	t_node	*stacka;

	stacka = NULL;
	ft_input_arg(argc, argv);
	stacka = ft_fillstack(argc, argv, stacka);
	ft_index(stacka);
	if (ft_is_sorted(stacka) == 0)
		ft_clearnodes(&stacka);
	else if (ft_stacksize(stacka) <= 3)
		ft_sort3(&stacka, 1);
	else if (ft_stacksize(stacka) > 3 && ft_stacksize(stacka) <= 5)
		ft_sort5(&stacka);
	else if (ft_stacksize(stacka) > 5)
		ft_bigsort2(&stacka);
	return (0);
}
/*----------------------------------------------------------------*/
