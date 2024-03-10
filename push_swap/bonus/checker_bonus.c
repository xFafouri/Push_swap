/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:12:49 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/09 21:40:35 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}



void	spliting_ac(t_data *data,char **split_arg, t_list *ar, t_list **stack_a, char *av)
{
	int j;
	int i;
	
	i = 0;
	j = 0;
	if (ft_strchr(&av[i], '.') || ft_strchr(&av[i], ',') || ft_strchr(&av[i], '\t'))
		error_exit();
	while (split_arg[j])
	{
		data->arg = ft_atoi(split_arg[j]);
		while (data->arg == 0 && split_arg[j][0] != '0')
		{
			if (split_arg[j][0] == '-' || split_arg[j][0] == '+')
				break ;
			error_exit();
		}
		ar = ft_lstnew(data->arg);
		ft_lst_add_back(stack_a, ar);
		j++;
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

	str = get_next_line(0);
	while (str != NULL)
	{
		check_moves(str, stack_a, stack_b);
		str = get_next_line(0);
	}
	if (check_if_sorted(stack_a) && (ft_lstsize(*stack_b) == 0))
		write(1,"OK\n",3);
	else
		write(1,"KO\n",3);
}

int main(int ac , char **av)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	t_list	*ar = NULL;
	t_data	data;
	int i;
	char **split_arg;

	data.node = 0;
	data.target = 0;
	data.above_node = 0;
	data.above_target = 0;
	i = 1;
	if (ac == 1)
		exit(0);
	if (!check_arg(av, ac))
		error_exit();
	while (i < ac)
	{
    	split_arg = ft_split(av[i], ' ');
		spliting_ac(&data, split_arg, ar, &stack_a, av[i]);
   		i++;
	}
	if (check_double(&stack_a))
		error_exit();
	ft_start(&stack_a, &stack_b);
}
