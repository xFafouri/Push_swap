/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:28:38 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/13 03:21:33 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	ft_strlen(const char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return(i);
}
int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

void	spliting_ac(t_data *data,char **split_arg, t_list *ar, t_list **stack_a)
{
	int j;
	int i;
	
	i = 0;
	j = 0;
	while (split_arg[j])
	{
		data->arg = ft_atoi(split_arg[j]);
		while (data->arg == 0 && split_arg[j][0] != '0')
		{
			if (split_arg[j][0] == '-' || split_arg[j][0] == '+')
				break ;
			free_stack(stack_a);
			error_exit();
		}
		ar = ft_lstnew(data->arg);
		ft_lst_add_back(stack_a, ar);
		j++;
	}
}

void	turk_sort_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while(ft_lstsize(*stack_a) > 3)
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
			while((*stack_b)->nbr != data->target)
			rrb(stack_b);
		}
		pb(stack_a, stack_b);
	}
}

void turk_sort_b(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while(ft_lstsize(*stack_b) > 0)
	{
		data->node = 0;
		data->target = target_of_b(stack_b, stack_a, &data->node);
		data->above_node = check_above1(*stack_b, data->node);
		data->above_target = check_above1(*stack_a, data->target);
		if (data->above_node && data->above_target)
			both_above2(stack_a, stack_b, data);
		else if(!data->above_node && !data->above_target)
			both_not_above2(stack_a, stack_b, data);
		if (data->above_node)
			node_above2(stack_b, data);
		else
			node_not_above2(stack_b, data);
		if (data->above_target)
			target_above2(stack_a, data);
		else
		{
			while((*stack_a)->nbr != data->target)
				rra(stack_a);
		}
		pa(stack_a, stack_b);
	}
}

void ft_start(t_list **stack_a, t_list **stack_b, t_data *data)
{
	if (check_double(stack_a))
		free_exit_error(stack_a);
	if (check_if_sorted(stack_a))
		free_and_exit(stack_a);
	if (ft_lstsize(*stack_a) == 2)
	{
		sort_two(stack_a);
		free_and_exit(stack_a);
	}
	if (ft_lstsize(*stack_a) == 3)
	{
		sort_three(stack_a);
		free_and_exit(stack_a);
	}
	else
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		turk_sort_a(stack_a, stack_b, data);
		sort_three(stack_a);
		turk_sort_b(stack_a, stack_b, data);
		check_min(stack_a);
	}
}

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*ar;
	t_data	data;
	int		i;
	char	**split_arg;

	data.node = 0;
	ar = NULL;
	data.target = 0;
	data.above_node = 0;
	data.above_target = 0;
	i = 1;
	if (!check_arg(av, ac))
		error_exit();
	while (i < ac)
	{
    	split_arg = ft_split(av[i], ' ');
		spliting_ac(&data, split_arg, ar, &stack_a);
		free_split(split_arg, count_words(av[i], ' '));
		i++;
	}
	ft_start(&stack_a, &stack_b , &data);
	return(free_stack(&stack_a),free_stack(&stack_b));
}
