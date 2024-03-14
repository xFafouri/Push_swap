/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:12:49 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/14 00:35:17 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"



void	spliting_ac(t_data *data,char **split_arg, t_list *ar, t_list **stack_a)
{
	int j;
	
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



void 	check_moves(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		error_exit();
}

void ft_start(t_list **stack_a, t_list **stack_b)
{
	
	char *str;

	if (check_double(stack_a))
	{
		free_stack(stack_a);
		error_exit();
	}
	str = get_next_line(0);
	while (str != NULL)
	{
		check_moves(str, stack_a, stack_b);
		str = get_next_line(0);
	}
	if (check_if_sorted(stack_a) && (ft_lstsize(*stack_b) == 0))
	{
		write(1,"OK\n",3);
		free_stack(stack_a);
	}
	else
	{
		write(1,"KO\n",3);
		free_stack(stack_a);
	}
}

int main(int ac , char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*ar;
	t_data	data;
	int i;
	char **split_arg;

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
	ft_start(&stack_a, &stack_b);
	return(free_stack(&stack_a),free_stack(&stack_b));
}
