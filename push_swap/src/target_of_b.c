/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_of_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 03:09:07 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/15 03:59:39 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_next_b(t_list **stack_a, t_list **stack_b, int *node, t_help *s1)
{
	t_list	*current;

	current = *stack_b;
	while (current != NULL)
	{
		s1->index_a = 0;
		s1->target = ft_check_target_b(current->nbr, stack_a);
		if (s1->target == LONG_MAX)
		{
			s1->target = smallest_one_a(stack_a);
			s1->index_a = index_of_smallest_one_a(stack_a);
		}
		s1->index_a = get_index(stack_a, s1->target);
		s1->total_cost = check_above(stack_b, stack_a, s1->index_b,
				s1->index_a);
		if (s1->total_cost < s1->min)
		{
			s1->min = s1->total_cost;
			*node = current->nbr;
			s1->target_f = s1->target;
		}
		s1->index_b++;
		current = current->next;
	}
	return (s1->target_f);
}

int	target_of_b(t_list **stack_b, t_list **stack_a, int *node)
{
	t_help	s1;

	s1.index_b = 0;
	s1.total_cost = 0;
	s1.index_a = 0;
	s1.target = 0;
	s1.target_f = 0;
	s1.min = LONG_MAX;
	s1.target_f = ft_next_b(stack_a, stack_b, node, &s1);
	return (s1.target_f);
}
