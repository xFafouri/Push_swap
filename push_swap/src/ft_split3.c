/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:31:08 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/10 02:42:52 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int check_sep (char str, char *sep)
{
	int i = 0;
	while(sep[i])
	{
		if (str == sep[i])
			return(1);
		i++;
	}
	return (0);
}

static int 	count_words(char *str, char *sep)
{
	int i = 0;
	int count = 0;;
	while ( str[i] != '\0')
	{
		while (str[i] != '\0' && check_sep(str[i], sep))
		{
			i++;
		}
		if (str[i])
			count++;
		while (str[i] != '\0' && !check_sep(str[i] , sep))
			i++;
	}
	return (count);
}

int len_until_sep(char *str, char *sep)
{
	int i = 0;

	while(str[i] != '\0' && !check_sep(str[i], sep))
		i++;
	return(i);
}

char	*ft_words (char *str, char *sep)
{
	int len = len_until_sep(str, sep);
	int i = 0;

	char *word = (char *)malloc(sizeof(char ) * len + 1);
	if (!word)
		return( NULL);
	while(i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return(word);
}
char	**ft_split(char *str,char *sep)
{
	int count = count_words(str, sep);
	int i = 0;
	
	char **s = (char **)malloc(sizeof(char *) * count + 1);
	while(*str != '\0')
	{
		if (!s)
			return(NULL);
		while (*str != '\0' && check_sep(*str, sep))
			str++;
		if (*str)
		{
			s[i] = ft_words(str, sep);
			i++; 
		}
		while (*str && !check_sep(*str, sep))
			str++;
	}
	s[i] = NULL;
	return(s);
}

