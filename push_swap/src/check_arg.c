/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 02:34:13 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/22 03:53:16 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	valide_arg1(int ac, char **av)
{
	int	i;
	int	size;

	i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i], '\t'))
			error_exit();
		size = ft_strlen(av[i]);
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
			if ((av[i][j] >= 'a' && av[i][j] <= 'z') || (av[i][j] >= 'A'
					&& av[i][j] <= 'Z'))
				error_exit();
			j++;
		}
		if (count == size)
			return (0);
		i++;
	}
	return (1);
}

int	valid_arg3(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (av[i] && i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '-' || av[i][j] == '+') && !(av[i][j + 1] >= 48
					&& av[i][j + 1] <= 57))
				return (0);
			if (j > 0 && (av[i][j] == '-' || av[i][j] == '+') && (av[i][j
					- 1] >= 48 && av[i][j - 1] <= 57))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg(char **av, int ac)
{
	int	i;

	if (ac == 1)
		exit(0);
	i = 1;
	if (!valide_arg1(ac, av))
		return (0);
	if (!valide_arg2(av, ac))
		return (0);
	if (!valid_arg3(av, ac))
		return (0);
	return (1);
}
