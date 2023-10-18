/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 03:48:15 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/03 22:42:28 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_a(t_int **stacka)
{
    t_int *node;

    // Create a new node to hold the value of the current top element
    node = ft_lst_int_new((*stacka)->num);
    // Adjust the pointers to insert the new node in between the top two nodes
    node->next = (*stacka)->next->next;
    (*stacka)->next->next = node;
    // Remove the previous top node (the second element)
    ft_free_top(stacka);
    // Print a message indicating the operation ("sa" likely means "swap a")
    ft_printf("sa\n");
}

void	ft_swap_b(t_int **stackb)
{
    t_int *node;

    node = ft_lst_int_new((*stackb)->num);
    node->next = (*stackb)->next->next;
    (*stackb)->next->next = node;
    ft_free_top(stackb);
    ft_printf("sb\n");
}
