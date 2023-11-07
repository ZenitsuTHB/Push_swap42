/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:34:12 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/05 23:40:34 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//I comment the line iterator = stack in my ft_index in utills.
static  t_node  find_biggest_index(t_node **stack)
{
     t_node  *max_node;
        t_node  *current_node;

        max_node = *stack;
        current_node = (*stack)->next;
        while (current_node)
        {
                if (current_node->num > max_node->num)
                        max_node = current_node;
                current_node = current_node->next;
        }
        return (*max_node);
}
int main()
{
	t_node *max = NULL;
    // Create a sample linked list
    t_node* head = (t_node*)malloc(sizeof(t_node));
    head->num = 4;
    head->next = (t_node*)malloc(sizeof(t_node));
    head->next->num = 2;
    head->next->next = (t_node*)malloc(sizeof(t_node));
    head->next->next->num = 3;
    head->next->next->next = NULL;

	*max = find_biggest_index(&head);

	printf("value= %d\nindex = %d\n", max->num,max->index);
	return 0;
}
