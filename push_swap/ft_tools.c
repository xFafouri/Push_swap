/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 02:03:50 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/07 02:57:35 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void error_exit()
{
	printf("Error\n");
	exit(1);
}

int	ft_atoi(const char *s)
{
	long sign;
	long r;
	int i;

	i = 0;
	sign = 1;
	r = 0;
	
	while(s[i])
	{
		if ((s[i] == '-' || s[i] == '+' ) && !(s[i + 1] >= 48 && s[i + 1] <= 57))
			error_exit();
		i++;
	}
	i = 0;
	while(s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			error_exit();
		i++;
	}
	i = 0;
	while (s[i] >= '\t' && s[i] <= '\r' && s[i] != ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i - 1] >= '0' && s[i - 1] <= '9')
			error_exit();
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + (s[i] - '0');
		if ((r * sign) > 2147483647 || (r * sign) < -2147483648)
			error_exit();
		i++;
	}
	if (s[i] != '\0')
		return(0);
	return (r * sign);
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
