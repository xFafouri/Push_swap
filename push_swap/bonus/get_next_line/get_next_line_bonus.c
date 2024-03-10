/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:26:26 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/09 02:25:31 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*line(char *str)
{
	int		i;
	int		j;
	char	*s;

	j = 0;
	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i])
		i++;
	s = (char *)malloc(i + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		s[j++] = str[i++];
	if (str[i] == '\n')
	{
		s[j] = '\n';
		j++;
	}
	s[j] = '\0';
	return (s);
}

static char	*chiyata(char *str)
{
	char	*s;
	int		j;
	int	i;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	s = malloc(ft_strlen(str) - i + 1);
	if (!s)
		return (NULL);
	if (str[i] == '\n')
		i++;
	while (str[i] != '\0')
		s[j++] = str[i++];
	s[j] = '\0';
	free(str);
	return (s);
}

static char	*until_nl(int fd, char *s)
{
	char	*buff;
	ssize_t	ret;

	ret = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			free(s);
			return (NULL);
		}
		else if (ret == 0)
			break ;
		buff[ret] = '\0';
		s = ft_strjoin(s, buff);
		if (ft_strchr(s, '\n'))
			break ;
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*s;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
	{
		return (NULL);
	}
	str[fd] = until_nl(fd, str[fd]);
	if (str[fd] == NULL)
		return (NULL);
	s = line(str[fd]);
	str[fd] = chiyata(str[fd]);
	return (s);
}
