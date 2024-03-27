/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_above.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:52:28 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/18 07:29:25 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	check_above1(t_list *stack, int node)
{
	int	size;
	int	i;

	size = ft_lstsize(stack);
	i = 0;
	while (stack != NULL)
	{
		if (stack->nbr == node)
			break ;
		i++;
		stack = stack->next;
	}
	return (i <= size / 2);
}

int	check_above(t_list **stack_a, t_list **stack_b, int index_a, int index_b)
{
	int	size_a;
	int	size_b;
	int	cost;

	size_b = ft_lstsize(*stack_b);
	size_a = ft_lstsize(*stack_a);
	cost = 0;
	if (index_a <= size_a / 2 && index_b <= size_b / 2)
		cost = ft_max(index_a, index_b);
	else if (index_a > size_a / 2 && index_b > size_b / 2)
		cost = ft_max(size_a - index_a, size_b - index_b);
	else
	{
		if (index_a <= size_a / 2)
			cost = index_a;
		else
			cost = size_a - index_a;
		if (index_b <= size_b / 2)
			cost += index_b;
		else
			cost += size_b - index_b;
	}
	return (cost);
}
