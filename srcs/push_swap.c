/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:15:53 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/23 22:05:31 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*ft_fillstack(int argc, char **argv, t_node *stack)
{
	int		i;
	t_node	*aux;

	if (argc == 2)
	{
		i = 0;
		argv = ft_split(argv[1], ' ');
	}
	else
		i = 1;
	stack = malloc(sizeof(t_node));
	if (!stack)
		return (NULL);
	aux = stack;
	while (argv[i])
	{
	//	printf("argv[%d] -> %s\n", i, argv[i]);
		stack->num = ft_atoi(argv[i]);
		//stack->prev =;
		stack->next = malloc(sizeof(t_node));
		// El ultimo caso no se guardara bien!!!!! s[i + 1] .....
		if (!stack->next)
			return(NULL); // SI FALLA UN MALLOX TINES QUE LIBERAR LO ANTERIOR
		stack = stack->next;
		i++;
	}
	int j = 1;
	while (stack->next){
		printf("this is the [%d] node --> %d\n", j, stack->num);
	}
	return (aux);
}

int	main(int argc, char **argv)
{
	t_node *stack_a;

	stack_a = NULL;
	ft_input_arg(argc, argv);
	stack_a = ft_fillstack(argc, argv, stack_a);
	return (0);
}
