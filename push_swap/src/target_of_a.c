/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_of_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 03:07:04 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/15 03:59:07 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_next_a(t_list **stack_a, t_list **stack_b, int *node, t_help *s)
{
	t_list	*current;

	current = *stack_a;
	while (current != NULL)
	{
		s->target = ft_check_target_a(current->nbr, stack_b);
		if (s->target == LONG_MIN)
		{
			s->target = bigger_one_b(stack_b);
			s->index_b = index_of_bigger_one_a(stack_b);
		}
		s->index_b = get_index(stack_b, s->target);
		s->total_cost = check_above(stack_a, stack_b, s->index, s->index_b);
		if (s->total_cost < s->min)
		{
			s->min = s->total_cost;
			*node = current->nbr;
			s->target_f = s->target;
		}
		s->index++;
		current = current->next;
	}
	return (s->target_f);
}

int	target_of_a(t_list **stack_a, t_list **stack_b, int *node)
{
	t_help	s;

	s.index = 0;
	s.total_cost = 0;
	s.index_b = 0;
	s.target = 0;
	s.target_f = 0;
	s.min = LONG_MAX;
	s.target_f = ft_next_a(stack_a, stack_b, node, &s);
	return (s.target_f);
}
