/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 02:03:50 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/13 00:57:56 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_double(t_list **stack_a)
{
	int nb = 0;
    t_list	*current;
	t_list	*after;
	
	current = *stack_a;
    while(current != NULL)
    {
        nb = current->nbr;
        after = current;
        while(after->next != NULL)
        {
            if (after->next->nbr == nb)
				return(1);
            after = after->next;
        }
        current = current->next;
    }
	return (0);
}

void error_exit()
{
	write(2,"Error\n",6);
	exit(1);
}

void check_sign(const char *s, int *i, int *sign)
{
    if (s[*i] == '+' || s[*i] == '-')
    {
        if (s[*i] == '-')
            *sign *= -1;
        (*i)++;
    }
}

void check_digit(const char *s, long *r, int *i, int *sign)
{
    while (s[*i] >= '0' && s[*i] <= '9')
    {
        *r = *r * 10 + (s[*i] - '0');
        if ((*r * *sign) > 2147483647 || (*r * *sign) < -2147483648)
            error_exit();
        (*i)++;
    }
}

long	ft_atoi(const char *s)
{
	int sign;
	int i;
	long r;

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
	check_sign(s, &i, &sign);
    check_digit(s, &r, &i, &sign);
	if (s[i] != '\0')
        error_exit();
    return (r * sign);
}
