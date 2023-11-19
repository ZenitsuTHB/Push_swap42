/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:15:53 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/18 19:35:23 by avolcy           ###   ########.fr       */
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

/*=================PUSH_SWAP_MAIN=============================*/
int	main(int argc, char **argv)
{
	t_node	*stacka;

	stacka = NULL;
	ft_input_arg(argc, argv);
	stacka = ft_fillstack(argc, argv, stacka);
//	ft_index(stacka);
//	print_stack(stacka);
	if (ft_is_sorted(stacka) == 0)
		ft_clearnodes(&stacka);
	else if (ft_stacksize(stacka) <= 3)
		ft_sort3(&stacka, 1);
	else if (ft_stacksize(stacka) > 3 && ft_stacksize(stacka) <= 5)
		ft_sort5(&stacka);
	else if (ft_stacksize(stacka) > 5)
		ft_bigsort(&stacka);
	return (0);
}
/*------------------------------------------------------------*/
