/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:05:25 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/02 18:09:39 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **stack)
{
	if (ft_lstsize(*stack) < 2)
		return ;
	t_list *tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next; 
	tmp->next = (*stack);
	(*stack) = tmp;
}
void sa(t_list **stack_a)
{
	swap(stack_a);
	write(1,"sa\n",3);
}
void sb(t_list **stack_b)
{
	swap(stack_b);
	write(1,"sb\n",3);
}
void ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1,"ss\n",3);
}
