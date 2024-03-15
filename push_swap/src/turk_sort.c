/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:44:54 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/15 03:45:17 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sort_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		data->node = 0;
		data->target = target_of_a(stack_a, stack_b, &data->node);
		data->above_node = check_above1(*stack_a, data->node);
		data->above_target = check_above1(*stack_b, data->target);
		if (data->above_node && data->above_target)
			both_above1(stack_a, stack_b, data);
		else if (!data->above_node && !data->above_target)
			both_not_above1(stack_a, stack_b, data);
		if (data->above_node)
			node_above1(stack_a, data);
		else
			node_not_above1(stack_a, data);
		if (data->above_target)
			target_above1(stack_b, data);
		else
		{
			while ((*stack_b)->nbr != data->target)
				rrb(stack_b);
		}
		pb(stack_a, stack_b);
	}
}

void	turk_sort_b(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while (ft_lstsize(*stack_b) > 0)
	{
		data->node = 0;
		data->target = target_of_b(stack_b, stack_a, &data->node);
		data->above_node = check_above1(*stack_b, data->node);
		data->above_target = check_above1(*stack_a, data->target);
		if (data->above_node && data->above_target)
			both_above2(stack_a, stack_b, data);
		else if (!data->above_node && !data->above_target)
			both_not_above2(stack_a, stack_b, data);
		if (data->above_node)
			node_above2(stack_b, data);
		else
			node_not_above2(stack_b, data);
		if (data->above_target)
			target_above2(stack_a, data);
		else
		{
			while ((*stack_a)->nbr != data->target)
				rra(stack_a);
		}
		pa(stack_a, stack_b);
	}
}
