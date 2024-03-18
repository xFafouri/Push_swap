/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:28:38 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/18 02:29:42 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	spliting_ac(t_data *data, char **split_arg, t_list *ar,
		t_list **stack_a)
{
	int	j;

	j = 0;
	while (split_arg[j])
	{
		data->arg = ft_atoi(split_arg[j], stack_a);
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

void	ft_start(t_list **stack_a, t_list **stack_b, t_data *data)
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

void	mini_main(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	t_list	*ar;
	t_data	data;
	char	**split_arg;
	int		i;

	data.node = 0;
	ar = NULL;
	data.target = 0;
	data.above_node = 0;
	data.above_target = 0;
	i = 1;
	while (i < ac)
	{
		split_arg = ft_split(av[i], ' ');
		spliting_ac(&data, split_arg, ar, stack_a);
		free_split(split_arg, count_words(av[i], ' '));
		i++;
	}
	ft_start(stack_a, stack_b, &data);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (!check_arg(av, ac))
		error_exit();
	mini_main(ac, av, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
