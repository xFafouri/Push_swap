/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 02:50:49 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/08 16:15:38 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int bigger_one_b(t_list **stack_b)
{
	int max;
	t_list *current = (*stack_b);
	max = current->nbr;
	while(current != NULL)
	{
		if (current->nbr > max)
		{
			max = current->nbr;
		}
		current = current->next;	
	}
	return(max);
}

int smallest_one_a(t_list **stack_a)
{
	int min;
	t_list *current = (*stack_a);
	min = current->nbr;
	while(current != NULL)
	{
		if (current->nbr < min)
		{
			min = current->nbr;
		}
		current = current->next;	
	}
	return(min);
}

int index_of_bigger_one_a(t_list **stack_b)
{
	int index = 0;

	t_list *current = (*stack_b);
	int max = bigger_one_b(stack_b);
	while (current != NULL)
	{
		if (current->nbr == max)
			return (index);
		index++;
		current = current->next;
	}
	return(-1);
}

int index_of_smallest_one_a(t_list **stack_a)
{
	int index = 0;
	int min = smallest_one_a(stack_a);
	t_list *current = (*stack_a);
	while(current != NULL)
	{
		if (current->nbr == min)
			return(index);
		index++;
		current = current->next;
	}
	return (-1);
}

int get_index(t_list **stack , int node)
{
	int index;

	index = 0;
	t_list *current = (*stack);
	while (current != NULL)
	{
		if (current->nbr == node)
			return(index);
		index++;
		current= current->next;
	}
	return (-1);
}
