/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:46:18 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/10 02:43:05 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	check_separator(char str, char *sep)
{
	int i = 0;
	while(sep[i])
	{
		if (str == sep[i])
			return (1);
		i++;
	}
	return (0);
}

static int		count_words(char *str,char *sep)
{
	int count = 0;
	int i = 0;

	while(str[i] != '\0')
	{
		while(str[i] && check_separator(str[i], sep))
		{
			i++;
		}
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !check_separator(str[i], sep))
		{
			i++;
		}
	}
	return(count);
}
// int main ()
// {
// 	printf("%d\n", count_words("hamza fafouri!test,", "! ,"));
// }
int	len_until_sep(char *str, char *sep)
{
	int i = 0;

	while(str[i] && !check_separator(str[i], sep))
		i++;
	return (i);
}

char	*ft_words(char *str, char *sep)
{
	int len_sep = len_until_sep(str, sep);
	char *word;
	int i = 0;

	word = (char *)malloc(sizeof(char) * (len_sep + 1));
	while(i < len_sep)
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
	char **s;
	int i = 0;

	s = (char **)malloc(sizeof(char *) * (count + 1));
	if (!s)
		return (NULL);
	while(*str != '\0')
	{
		while (*str && check_separator(*str, sep))
			str++;
		if (*str != '\0')
		{
			s[i] = ft_words(str, sep);
			i++;
		}
		while(*str && !check_separator(*str, sep))
			str++;
	}
	s[i] = NULL;
	return(s);
}
// int main()
// {
//     char *str = "hamza 	fafouri,test!";
//     char *sep = " 	!,";
//     char **result = ft_split(str, sep);
    
//     for (int i = 0; result[i] != NULL; i++)
//     {
//         printf("%s\n", result[i]);
//     }
//     return 0;
// }