/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 02:34:13 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/15 22:57:24 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	check_arg(char **av, int ac)
{
	int	i;
	int	size;

	i = 1;
	if (ac == 1)
		exit(0);
	if (ft_strchr(av[i], '.') || ft_strchr(av[i], ',') || ft_strchr(av[i],
			'\t'))
		error_exit();
	size = ft_strlen(av[i]);
	if (size == 0)
		return (0);
	if (!valide_arg1(size, ac, av))
		return (0);
	if (!valide_arg2(av, ac))
		return (0);
	return (1);
}
