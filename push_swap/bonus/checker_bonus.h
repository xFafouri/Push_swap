/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:21:45 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/12 15:58:20 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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
} t_data;

char	**ft_split(char *s, char c);
t_list	*ft_lstnew(int nb);
t_list	*ft_lstlast(t_list *lst);
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
void	ft_lst_add_back(t_list **lst, t_list *new);
void 	error_exit();
long	ft_atoi(const char *s);
int		ft_lstsize(t_list *lst);
int		valide_arg1(int size, int argc, char **argv);
int		valide_arg2(char **av, int ac);
int		check_arg(char **av, int ac);
void	reverse_rotate(t_list **stack);
void 	rotate(t_list **stack);
int		ft_strlen(const char *s);
char	**ft_split(char *s, char c);
int		valide_arg1(int size, int argc, char **argv);
int		valide_arg2(char **av, int ac);
int		check_arg(char **av, int ac);
int 	check_double(t_list **stack_a);
int		ft_strcmp(char *s1, char *s2);
int 	check_if_sorted(t_list **stack_a);

# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#endif
