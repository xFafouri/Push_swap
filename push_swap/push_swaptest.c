/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:28:38 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/02 17:52:38 by hfafouri         ###   ########.fr       */
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
void swap(t_list **stack)
{
	if (ft_lstsize(*stack) < 2)
		return ;
	t_list *tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next; 
	tmp->next = (*stack);
	(*stack) = tmp;
}
void sa(t_list **stack_a)
{
	swap(stack_a);
	write(1,"sa\n",3);
}
void sb(t_list **stack_b)
{
	swap(stack_b);
	write(1,"sb\n",3);
}
void ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1,"ss\n",3);
}

#include <stdio.h>

void rotate(t_list **stack)
{
	t_list *last_node;
	last_node = ft_lstlast(*stack);

    last_node->next = *stack; 
    *stack = (*stack)->next; 
    last_node->next->next = NULL;
}

void ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1,"ra\n",3);
}
void rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1,"rb\n",3);
}
void rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_b);
	rotate(stack_a);
	write(1,"rr\n",3);
}
void	reverse_rotate(t_list **stack)
{
	t_list *last_node;

	last_node = ft_lstlast(*stack);

	last_node->next = *stack;
	*stack = last_node;
	t_list *second_last = *stack;
	while(second_last->next != last_node)
	{
		second_last = second_last->next;
	}
	second_last->next = NULL;
}



// void	final_rank(t_list *stack_a)
// {
// 	stack_a->final_rank = 0;
// 	stack_a->final_rank = stack_a->nbr;
	
// 	t_list *current = stack_a->next;
// 	while(current != NULL)
// 	{
// 		if (current->nbr > stack_a->final_rank)
// 			stack_a->final_rank = current->nbr;
// 		current = current->next;
// 	}
// }
void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	if (!(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1,"pb\n",3);
}
void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	if (!(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp; 
}
void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1,"rrb\n",4);
}
void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1,"rrr\n",4);
}

void	rra(t_list **stack_a)
{	
	reverse_rotate(stack_a);
	write(1,"rra\n",4);
}


void	sort_three(t_list **stack_a)
{
	// 3 2 1
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
	// printf("nbr_op: %d\n",nbr_op);
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
	// printf("nbr_b = %d\n",nbr_b);
	return(nbr_b);
}


int bigger_one_b(t_list **stack_b)
{
	int max;
	t_list *current = (*stack_b);
	// printf("head = %d\n", current->nbr);
	max = current->nbr;
	while(current != NULL)
	{
		if (current->nbr > max)
		{
			max = current->nbr;
			// printf("max = %d\n", max);
		}
		current = current->next;	
	}
	// printf("max = %d\n", max);
	return(max);
}
void ft_check_target(int nb,t_list **stack_b, int *index_b, int *target)
{
	int index = 0;
	long best_b = LONG_MIN;
	// int less_op_b = 0;

	t_list *current = (*stack_b);
	while(current != NULL)
	{
		if (current->nbr  < nb && best_b < current->nbr)
		{
			best_b = current->nbr;
			// printf("bst_b %ld\n", best_b);
			*index_b = index;
		}
		index++;
		current = current->next;
	}
	// printf("best_b before if= %ld\n", best_b);
	if (best_b == LONG_MIN)
	{
		// printf("best_b in if = %ld\n", best_b);
		best_b = bigger_one_b(stack_b);
	}
	// printf("best_b2 = %ld\n", best_b);
	*target = best_b;
	// less_op_b = calculate_opp(stack_b, best_b);
	// return(less_op_b);
}


int ft_calcul_a(int index_a, t_list **stack_a)
{
	// int index_b = 0;
	// int	total_cost = 0;
	// int max_total = 0;
	int nbr_op = calculate_op(stack_a, index_a);
	// int nbr_target = ft_check_target(nbr, stack_b, &index_b);
	return (nbr_op);
}


int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int check_above(t_list **stack_a ,t_list **stack_b, int index_a, int index_b)
{
	int size_a = ft_lstsize(*stack_a);
	int size_b = ft_lstsize(*stack_b);
	int cost = 0;

	if (index_a <= size_a / 2 && index_b <= size_b / 2)
		cost = ft_max(index_a, index_b);
	else if (index_a > size_a / 2 && index_b > size_b / 2)
		cost = ft_max(size_a - index_a, size_b - index_b);
	else
		cost = index_a + index_b;

	return (cost);

}

int turk_sort(t_list **stack_a, t_list **stack_b, int *node)
{
	int	index = 0;
	int total_cost = 0;
	int index_b = 0;
	int target = 0;
	int target_f = 0;
	// int nbr_op = 0;
	// int nbr_target = 0;
	long min = LONG_MAX;
	
	t_list *current = *stack_a;
	while(current != NULL)
	{
		// ft_calcul_a(index, stack_a);
		ft_check_target(current->nbr, stack_b, &index_b, &target);
		// printf("node = %d | target = %d\n",current->nbr, target);
		total_cost = check_above(stack_a, stack_b, index, index_b);
		printf("cost %d & %d = %d\n", current->nbr, target, total_cost);
		// printf("index %d = %d | index %d = %d\n", current->nbr, index,  target, index_b);
		if (total_cost < min)
		{
			min = total_cost;
			*node = current->nbr;
			target_f = target;
		}
		index++;
		current = current->next;
		// printf("next node %d\n", current->nbr);
	}
	// printf("target_f %d\n", target_f);
	// printf("min cost = %ld\n", min);
	return (target_f);
	// printf("min : %ld\n", min);
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
	// printf("size %d | index %d\n", size, i);
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
}
int main (int ac, char **av)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	
	t_list *ar;
	int i;
	int j;
	int arg;
	char **split_arg;
	
	// stack_a->final_rank = 0;
	i = 1;

	while (i < ac)
	{
		if (strchr(av[i], '.') || strchr(av[i], ','))
		{
			printf("ERROR\n");
			return (0);
		}
		if (ac == 2)
		{
			j = 0; 
			split_arg = ft_split(av[i], " +");
			while (split_arg[j])
			{
				arg = ft_atoi(split_arg[j]);
				if (arg == 0 && split_arg[j][0] != '0')
				{
						printf("Error\n");
						return (0);
				}
				ar = ft_lstnew(arg);
				ft_lst_add_back(&stack_a, ar);
				j++;
			}
			break ;
		}
		arg = ft_atoi(av[i]);
		if (arg == 0 && av[i][0] != '0')
		{
			printf("Error\n");
			return (0);
		}
		ar = ft_lstnew(arg);
		ft_lst_add_back(&stack_a, ar);
		i++;
	}
	// if (ft_lstsize(stack_a) == 2)
	// {
	// 	sa(&stack_a);
	// }
	// if (ft_lstsize(stack_a) == 3)
	// {
	// 	sort_three(&stack_a);
	// }
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	while(ft_lstsize(stack_a) > 3)
	{
		int node = 0;
		int target = turk_sort(&stack_a, &stack_b, &node);
		// printf("node = %d | target = %d\n",node, target);
		int above_node = check_above1(stack_a, node);
		int above_target = check_above1(stack_b, target);
		if (above_node && above_target)
		{
			// printf("test\n");
			while(stack_a->nbr != node && stack_b->nbr != target)
			{
				rr(&stack_a, &stack_b);
			}
		}
		else
		{
			while(stack_a->nbr != node && stack_b->nbr != target)
			{
				rrr(&stack_a, &stack_b);
			}
		}
		if (above_node)
		{
			while(stack_a->nbr != node)
				ra(&stack_a);
			
		}
		else
		{
			while(stack_a->nbr != node)
				rra(&stack_a);
		}
		if (above_target)
		{
			while(stack_b->nbr != target)
				rb(&stack_b);
			
		}
		else
		{
			while(stack_b->nbr != target)
				rrb(&stack_b);
		}
		pb(&stack_a, &stack_b);
		
		ft_write(stack_a, stack_b);
			printf("\n");
		// sort_three(&stack_a);
	}
		// printf("target = %d, node = %d\n", target, node);
		// printf(" is abv :%d\n", check_above1(stack_a, node));
		// printf(" is abv target :%d\n", check_above1(stack_b, target));
		
	

	// while (stack_a != NULL)
	// {
	// 	printf("stack_a : %d\n", stack_a->nbr);
	// 	stack_a = stack_a->next;
	// }
	// while (stack_b != NULL)
	// {
	// 	printf("%d ", stack_b->nbr);
	// 	stack_b = stack_b->next;
	// }
	// printf("\n");
}
