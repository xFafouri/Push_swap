/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 01:52:34 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/06 19:10:40 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef	struct s_list
{
	int	nbr;
	struct s_list	*next;
} t_list;

typedef	struct s_data
{
	long arg;
	char **split_arg;
	int node;
	int target;
	int above_node;
	int above_target;
}t_data;

char	**ft_split(char *s, char c);
t_list	*ft_lstnew(int nb);
t_list	*ft_lstlast(t_list *lst);
void	ft_lst_add_back(t_list **lst, t_list *new);
int	ft_strlen(const char *s);
int		ft_atoi(const char *s);
int		ft_lstsize(t_list *lst);
void 	ra(t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void 	rr(t_list **stack_a, t_list **stack_b);
void 	rb(t_list **stack_b);
void 	swap(t_list **stack);
void 	sa(t_list **stack_a);
void 	sb(t_list **stack_b);
void 	ss(t_list **stack_a, t_list **stack_b);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	reverse_rotate(t_list **stack);
void 	rotate(t_list **stack);


#endif