/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:28:38 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/11 16:09:16 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)(s + i));
// 		i++;
// 	}
// 	if (s[i] == (char)c)
// 		return ((char *)(s + i));
// 	return (NULL);
// }

int target_of_b(t_list **stack_b, t_list **stack_a, int *node)
{
	int	index_b = 0;
	long total_cost = 0;
	int index_a;
	long target = 0;
	int target_f = 0;
	long min = LONG_MAX;
	
	t_list *current = *stack_b;
	while(current != NULL)
	{
		index_a = 0;
		target = ft_check_target_b(current->nbr, stack_a);
		if (target == LONG_MAX)
		{
			target = smallest_one_a(stack_a);
			index_a = index_of_smallest_one_a(stack_a);
		}
		index_a = get_index(stack_a, target);
		total_cost = check_above(stack_b, stack_a, index_b, index_a);
		if (total_cost < min)
		{
			min = total_cost;
			*node = current->nbr;
			target_f = target;
		}
		index_b++;
		current = current->next;
	}
	return (target_f);;
}

int target_of_a(t_list **stack_a, t_list **stack_b, int *node)
{
	int	index = 0;
	int total_cost = 0;
	int index_b = 0;
	long target = 0;
	int target_f = 0;
	long min = LONG_MAX;
	
	t_list *current = *stack_a;
	while(current != NULL)
	{
		target = ft_check_target_a(current->nbr, stack_b);
		if (target == LONG_MIN)
		{
			target = bigger_one_b(stack_b);
			index_b = index_of_bigger_one_a(stack_b);
		}
		index_b = get_index(stack_b, target);
		total_cost = check_above(stack_a, stack_b, index, index_b);
		if (total_cost < min)
		{
			min = total_cost;
			*node = current->nbr;
			target_f = target;
		}
		index++;
		current = current->next;
	}
	return (target_f);;
}


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
void	free_and_exit(t_list **stack_a)
{
	free_stack(stack_a);
	exit(0);
}
void ft_start(t_list **stack_a, t_list **stack_b, t_data *data)
{
	if (check_double(stack_a))
		free_and_exit(stack_a);
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

// char	**ft_free(char **s,int n)
// {
// 	while (n > 0)
// 	{
// 		free(s[n--]);
// 	}
// 	free(s);
// 	return (0);
// }
void free_split(char **array, int size)
{
	int i = 0;
    while (i < size) 
	{
        free(array[i]);
		i++;
    }
    free(array);
}

int main(int ac, char **av)
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
		spliting_ac(&data, split_arg, ar, &stack_a);
		free_split(split_arg, count_words(av[i], ' '));
		i++;
	}
	ft_start(&stack_a, &stack_b , &data);
	return(free_stack(&stack_a),free_stack(&stack_b));
}
