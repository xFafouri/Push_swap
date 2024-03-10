/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_targets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 02:54:46 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/08 16:05:31 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long ft_check_target_a(int nb,t_list **stack_b)
{
	int index = 0;
	long best_b = LONG_MIN;
	long target = 0;

	t_list *current = (*stack_b);
	while(current != NULL)
	{
		if (current->nbr < nb && best_b < current->nbr)
		{
			best_b = current->nbr;
		}
		index++;
		current = current->next;
	}
	target = best_b;
	return (target);
}

long ft_check_target_b(int nb,t_list **stack_a)
{
	int index = 0;
	long best_a = LONG_MAX;
	long target = 0;

	t_list *current = (*stack_a);
	while(current != NULL)
	{
		if (current->nbr > nb && best_a > current->nbr)
		{
			best_a = current->nbr;

		}
		index++;
		current = current->next;
	}
	target = best_a;
	return (target);
}
