/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 03:14:01 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/18 02:33:58 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_split(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_exit_error(t_list **stack_a)
{
	free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

int	free_stack(t_list **stack)
{
	t_list	*tmp;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	return (0);
}
