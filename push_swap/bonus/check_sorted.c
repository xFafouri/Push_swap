/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:34:47 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/15 04:10:57 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_if_sorted(t_list **stack_a)
{
	int		i;
	t_list	*current;

	current = *stack_a;
	if (stack_a == NULL || *stack_a == NULL)
		return (0);
	i = 1;
	while (current->next != NULL)
	{
		if (current->nbr < current->next->nbr)
		{
			i++;
		}
		current = current->next;
	}
	if (ft_lstsize(*stack_a) == i)
		return (1);
	return (0);
}
