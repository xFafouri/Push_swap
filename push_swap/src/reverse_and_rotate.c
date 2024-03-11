/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_and_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:58:45 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/04 02:27:56 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list *last_node;

	last_node = ft_lstlast(*stack);
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	return ;

	last_node->next = *stack;
	*stack = last_node;
	t_list *second_last = *stack;
	while(second_last->next != last_node)
	{
		second_last = second_last->next;
	}
	second_last->next = NULL;
}

void rotate(t_list **stack)
{
	t_list *last_node;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	last_node = ft_lstlast(*stack);
    last_node->next = *stack; 
    *stack = (*stack)->next; 
    last_node->next->next = NULL;
}