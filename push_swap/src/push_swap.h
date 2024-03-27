/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 01:52:34 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/21 00:35:18 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
}					t_list;

typedef struct s_help
{
	int				index;
	int				total_cost;
	int				index_b;
	int				index_a;
	long			target;
	int				target_f;
	long			min;

}					t_help;

typedef struct s_data
{
	long			arg;
	char			**split_arg;
	int				node;
	int				target;
	int				above_node;
	int				above_target;
}					t_data;

char				**ft_split(char *s, char c);
t_list				*ft_lstnew(int nb);
t_list				*ft_lstlast(t_list *lst);

void				ft_lst_add_back(t_list **lst, t_list *new);
int					ft_strlen(const char *s);
long				ft_atoi(const char *s, t_list **stack_a);
int					ft_lstsize(t_list *lst);
void				ra(t_list **stack_a);
void				pb(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rb(t_list **stack_b);
void				swap(t_list **stack);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				reverse_rotate(t_list **stack);
void				rotate(t_list **stack);
void				error_exit(void);
void				both_above1(t_list **stack_a, t_list **stack_b,
						t_data *data);
void				both_not_above1(t_list **stack_a, t_list **stack_b,
						t_data *data);
void				node_above1(t_list **stack_a, t_data *data);
void				node_not_above1(t_list **stack_a, t_data *data);
void				target_above1(t_list **stack_b, t_data *data);
void				both_above2(t_list **stack_a, t_list **stack_b,
						t_data *data);
void				both_not_above2(t_list **stack_a, t_list **stack_b,
						t_data *data);
void				node_above2(t_list **stack_b, t_data *data);
void				node_not_above2(t_list **stack_b, t_data *data);
void				target_above2(t_list **stack_a, t_data *data);
int					valide_arg1(int argc, char **argv);
int					valide_arg2(char **av, int ac);
int					check_arg(char **av, int ac);
int					bigger_one_b(t_list **stack_b);
int					smallest_one_a(t_list **stack_a);
int					index_of_bigger_one_a(t_list **stack_b);
int					index_of_smallest_one_a(t_list **stack_a);
int					get_index(t_list **stack, int node);
long				ft_check_target_a(int nb, t_list **stack_b);
long				ft_check_target_b(int nb, t_list **stack_a);
void				sort_three(t_list **stack_a);
void				sort_two(t_list **stack_a);
int					check_above(t_list **stack_a, t_list **stack_b, int index_a,
						int index_b);
void				check_min(t_list **stack_a);
int					check_above1(t_list *stack, int node);
int					check_if_sorted(t_list **stack_a);
int					check_double(t_list **stack_a);
int					smallest_one_a(t_list **stack_a);
char				**ft_free(char **s, int n);
int					free_stack(t_list **stack);
void				free_exit_error(t_list **stack_a);
void				free_and_exit(t_list **stack_a);
void				free_split(char **array, int size);
int					count_words(char *s, char c);
int					target_of_a(t_list **stack_a, t_list **stack_b, int *node);
int					ft_next_a(t_list **stack_a, t_list **stack_b, int *node,
						t_help *s);
int					ft_next_b(t_list **stack_a, t_list **stack_b, int *node,
						t_help *s1);
int					target_of_b(t_list **stack_b, t_list **stack_a, int *node);
int					ft_strcmp(char *s1, char *s2);
void				turk_sort_a(t_list **stack_a, t_list **stack_b,
						t_data *data);
void				turk_sort_b(t_list **stack_a, t_list **stack_b,
						t_data *data);

#endif