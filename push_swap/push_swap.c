/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:28:38 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/08 01:26:18 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}


void	sort_three(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 3)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->nbr > (*stack_a)->next->next->nbr)
		{
			ra(stack_a);
			if ((*stack_a)->nbr > (*stack_a)->next->nbr)
				sa(stack_a);
		}
		// 1 3 2
		else if ((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->next->nbr > (*stack_a)->next->next->nbr)
		{
			rra(stack_a);
			if ((*stack_a)->nbr > (*stack_a)->next->nbr)
				sa(stack_a);
		}
		// 1 2 3
		else if ((*stack_a)->next->next->nbr > (*stack_a)->nbr && (*stack_a)->next->next->nbr > (*stack_a)->next->nbr)
		{
			if ((*stack_a)->nbr > (*stack_a)->next->nbr)
				sa(stack_a);
		}
	}
	
}


int calculate_op(t_list **stack, int index) 
{
	int nbr_op = 0;
	int size = ft_lstsize(*stack);
	if (index < size / 2)
	{
		nbr_op = index;
	}
	else 
		nbr_op = size - index;
    return nbr_op;
}

int	calculate_opp(t_list **stack_b, int nb)
{
	int index = 0;
	int nbr_b = 0;

	
	t_list *current = (*stack_b);
	while (current != NULL)
	{
		if (current->nbr == nb)
		{
			nbr_b = calculate_op(stack_b, index);
		}
		index++;
		current = current->next;
	}
	return(nbr_b);
}


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
long ft_check_target_a(int nb,t_list **stack_b)
{
	int index = 0;
	long best_b = LONG_MIN;
	long target = 0;

	t_list *current = (*stack_b);
	while(current != NULL)
	{
		if (current->nbr < nb && best_b < current->nbr)
		{
			best_b = current->nbr;
		}
		index++;
		current = current->next;
	}
	// if (best_b == LONG_MIN)
	// {
	// 	best_b = bigger_one_b(stack_b);
	// 	*index_b = index_of_bigger_one_a(stack_b);
	// }
	target = best_b;
	return (target);
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
long ft_check_target_b(int nb,t_list **stack_a)
{
	int index = 0;
	long best_a = LONG_MAX;
	long target = 0;

	t_list *current = (*stack_a);
	while(current != NULL)
	{
		if (current->nbr > nb && best_a > current->nbr)
		{
			best_a = current->nbr;
			// printf("indexxx %d\n", index);
			// *index_a = index;
		}
		index++;
		current = current->next;
	}
	// if (best_a == LONG_MAX)
	// {
	// 	best_a = smallest_one_a(stack_a);
	// 	*index_a = index_of_smallest_one_a(stack_a);
	// }
	target = best_a;
	return (target);
}


int ft_calcul_a(int index_a, t_list **stack_a)
{
	int nbr_op = calculate_op(stack_a, index_a);
	return (nbr_op);
}


int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
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
int check_above(t_list **stack_a ,t_list **stack_b, int index_a, int index_b)
{
	int size_a = ft_lstsize(*stack_a);
	int size_b = ft_lstsize(*stack_b);
	// int index_a = get_index(stack_a, node);
	int cost = 0;
	// printf("index a = %d | index b = %d\n", index_a, index_b);
	if (index_a <= size_a / 2 && index_b <= size_b / 2)
	{
		cost = ft_max(index_a, index_b);
		// printf("(size_a = %d | size_b = %d)\n", size_a, size_b);
		// printf("(index_a = %d | index_b = %d)\n", index_a, index_b);
		// printf("COST = %d\n", cost);
		// printf("both above\n");
	}
	else if (index_a > size_a / 2 && index_b > size_b / 2)
	{
		cost = ft_max(size_a - index_a, size_b - index_b);
		// printf("(size_a = %d | size_b = %d)\n", size_a, size_b);
		// printf("(index_a = %d | index_b = %d)\n", index_a, index_b);
		// printf("COST NODE = %d  |  COST TARGET %d\n", (size_a - index_a), (size_b - index_b));	
		// printf("COST = %d\n", cost);
	}
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
		// printf("one one\n");

	return (cost);

}

int target_of_b(t_list **stack_b, t_list **stack_a, int *node)
{
	// printf("node a: %d | node b: %d\n", (*stack_a)->nbr, (*stack_b)->nbr);
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
int 	check_above1(t_list *stack, int node)
{
	int size = ft_lstsize(stack);
	int i = 0;
	while(stack != NULL)
	{
		if (stack->nbr == node)
			break;
		i++;
		stack = stack->next;
	}
	return(i <= size / 2);
}

void ft_write(t_list *stack_a, t_list *stack_b)
{
	printf("stack_a: ");
	while (stack_a != NULL)
	{
		printf("%d ", stack_a->nbr);
		stack_a = stack_a->next;
	}
	printf("\nstack_b: ");
	while (stack_b != NULL)
	{
		printf("%d ", stack_b->nbr);
		stack_b = stack_b->next;
	}
	printf("\n");

}

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
void sort_stack(t_list **stack_a, t_list **stack_b)
{
    while (*stack_a != NULL)
    {
        int max = smallest_one_a(stack_a);
        while ((*stack_a)->nbr != max)
        {
            ra(stack_a);
        }
        pb(stack_a, stack_b);
    }
	while(*stack_b != NULL)
	{
		pa(stack_a, stack_b);
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


void	sort_two(t_list **stack_a)
{
	t_list *current = (*stack_a);
	if (current->nbr > current->next->nbr)
			sa(stack_a);
}
// int is_number(const char s)
// {
// 	if (s >= '0' && s <= '9')
// 	{
// 		return (1);
// 	}
// 	return(0);
// }
int	ft_strlen(const char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return(i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}


int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return(1);
	return(0);
}

void spliting_ac(t_data *data,char **split_arg, t_list *ar, t_list **stack_a, char *av)
{
	int j;
	int i;
	
	i = 0;
	j = 0;
	if (ft_strcmp(&av[i],"") == 0)
		error_exit();
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

void both_above(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while((*stack_a)->nbr != data->node && (*stack_b)->nbr != data->target)
	{
		rr(stack_a, stack_b);
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
			{
				both_above(stack_a, stack_b, data);
				// while((*stack_a)->nbr != data->node && (*stack_b)->nbr != data->target)
				// {
				// 	rr(stack_a, stack_b);
				// }
			}
			else if (!data->above_node && !data->above_target)
			{
				while((*stack_a)->nbr != data->node && (*stack_b)->nbr != data->target)
				{
					rrr(stack_a, stack_b);
				}
			}
			if (data->above_node)
			{
				while((*stack_a)->nbr != data->node)
					ra(stack_a);
			}
			else
			{
				while((*stack_a)->nbr != data->node)
					rra(stack_a);
			}
			if (data->above_target)
			{
				while((*stack_b)->nbr != data->target)
					rb(stack_b);
			}
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
			{
				while((*stack_a)->nbr != data->target && (*stack_b)->nbr != data->node)
					rr(stack_a, stack_b);
			}
			else if(!data->above_node && !data->above_target)
			{
				while((*stack_b)->nbr != data->node && (*stack_a)->nbr != data->target)
					rrr(stack_a, stack_b);
			}
			if (data->above_node)
			{
				while((*stack_b)->nbr != data->node)
					rb(stack_b);
			}
			else
			{
				while((*stack_b)->nbr != data->node)
					rrb(stack_b);
			}
			if (data->above_target)
			{
				while((*stack_a)->nbr != data->target)
					ra(stack_a);
			}
			else
			{
				while((*stack_a)->nbr != data->target)
					rra(stack_a);
			}
			pa(stack_a, stack_b);
		}
}
 

int	valide_arg1(int size, int argc, char **argv)
{
	int	i;

	i = 1;
	while (size != 0 && i < argc)
	{
		size = ft_strlen(argv[i]);
		if (size == 0)
			return (0);
		i++;
	}
	return (1);
}

int	valide_arg2(char **av, int ac)
{
	int	i;
	int	j;
	int	count;
	int	size;


	i = 1;
	while (av[i] && i < ac)
	{
		count = 0;
		j = 0;
		size = ft_strlen(av[i]);
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				count++;
			j++;
		}
		if (count == size)
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(char **av, int ac)
{
	int	i;
	int	size;
	int	j;

	j = 0;
	i = 1;
	size = ft_strlen(av[i]);
	if (size == 0)
		return (0);
	if (!valide_arg1(size, ac, av))
		return (0);
	if (!valide_arg2(av, ac))
		return (0);
	return (1);
}

void ft_start(t_list **stack_a, t_list **stack_b, t_data *data)
{
	if (check_double(stack_a))
		error_exit();
	if (check_if_sorted(stack_a))
		exit(0);
	if (ft_lstsize(*stack_a) == 2)
	{
		sort_two(stack_a);
		exit(0);
	}
	if (ft_lstsize(*stack_a) == 3)
	{
		sort_three(stack_a);
		exit(0);
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
	ft_start(&stack_a, &stack_b , &data);
}
