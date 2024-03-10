/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 02:58:41 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/08 02:59:45 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 3)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->nbr > (*stack_a)->next->next->nbr)
		{
			ra(stack_a);
			if ((*stack_a)->nbr > (*stack_a)->next->nbr)
				sa(stack_a);
		}
		else if ((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->next->nbr > (*stack_a)->next->next->nbr)
		{
			rra(stack_a);
			if ((*stack_a)->nbr > (*stack_a)->next->nbr)
				sa(stack_a);
		}
		else if ((*stack_a)->next->next->nbr > (*stack_a)->nbr && (*stack_a)->next->next->nbr > (*stack_a)->next->nbr)
		{
			if ((*stack_a)->nbr > (*stack_a)->next->nbr)
				sa(stack_a);
		}
	}
}

void	sort_two(t_list **stack_a)
{
	t_list *current = (*stack_a);
	if (current->nbr > current->next->nbr)
			sa(stack_a);
}