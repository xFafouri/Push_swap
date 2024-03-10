/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:05:25 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/09 02:50:48 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

}
void sb(t_list **stack_b)
{
	swap(stack_b);

}
void ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);

}
