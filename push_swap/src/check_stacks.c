/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:10:20 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/08 16:15:47 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_min(t_list **stack_a)
{
	int min = smallest_one_a(stack_a);
	while ((*stack_a)->nbr != min)
	{
		if (check_above1(*stack_a, min))
		{
			ra(stack_a);
		}
		else
			rra(stack_a);
	}
}

int check_if_sorted(t_list **stack_a)
{
	int i = 1;
	t_list *current = (*stack_a);
	while(current->next != NULL)
	{
		if (current->nbr < current->next->nbr)
		{
			i++;
		}
		current = current->next;
	}
	if (ft_lstsize(*stack_a) == i)
		return (1);
	return(0);
}
int check_double(t_list **stack_a)
{
	int nb = 0;
    t_list *current = *stack_a;
    while(current != NULL)
    {
        nb = current->nbr;
        t_list *after = current;
        while(after->next != NULL)
        {
            if (after->next->nbr == nb)
            {
				return(1);
            }
            after = after->next;
        }
        current = current->next;
    }
	return (0);
}
