/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:11:51 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/11 16:09:08 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_lstclear(t_list **lst)
{
	t_list *tmp;
	while(*lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

int free_stack(t_list **stack)
{

	t_list *tmp;
	while(*stack!= NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	return(0);
}

t_list	*ft_lstnew(int nb)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->nbr = nb;
	node->next = NULL;
	return(node);
}
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
void	ft_lst_add_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		++counter;
	}
	return (counter);
}