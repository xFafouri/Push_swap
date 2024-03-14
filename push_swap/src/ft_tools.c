/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 02:03:50 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/13 03:54:33 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_sign(const char *s, int *i, int *sign)
{
	while (s[*i] >= '\t' && s[*i] <= '\r' && s[*i] != ' ')
		(*i)++;
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

void error_exit()
{
	write(2,"Error\n",6);
	exit(1);
}

void ft_non_digit(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		error_exit();
}
long	ft_atoi(const char *s)
{
	t_help1 help1;

	help1.i = 0;
	help1.sign = 1;
	help1.r = 0;
	while(s[help1.i])
	{
		if ((s[help1.i] == '-' || s[help1.i] == '+' ) && !(s[help1.i + 1] >= 48 && s[help1.i + 1] <= 57))
			error_exit();
		if ((s[help1.i] == '-' || s[help1.i] == '+' ) && (s[help1.i - 1] >= 48 && s[help1.i - 1] <= 57))
			error_exit();
		help1.i++;
	}
	help1.i = 0;
	while(s[help1.i])
	{
		ft_non_digit(s[help1.i]);
		help1.i++;
	}
	help1.i = 0;
	check_sign(s, &help1.i, &help1.sign);
    check_digit(s, &help1.r, &help1.i, &help1.sign);
	if (s[help1.i] != '\0')
		return(0);
	return(help1.r * help1.sign);
}
