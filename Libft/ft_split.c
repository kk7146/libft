/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:51:44 by eun               #+#    #+#             */
/*   Updated: 2023/10/18 11:24:49 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *str, char charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == charset)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !(str[i] == charset))
			i++;
	}
	return (count);
}

static int	len_word(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !(str[i] == charset))
		i++;
	return (i);
}

static char	*fill(char *str, char charset)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	len = len_word(str, charset);
	if (!str)
		return (NULL);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_all(char	**result, int i)
{
	while (i)
		free(result[--i]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*st;
	int		i;
	int		j;

	st = (char *)s;
	j = count_word(st, c);
	result = (char **)malloc((j + 1) * (sizeof(char *)));
	if ((!result))
		return (NULL);
	i = 0;
	while (*st != '\0' && j--)
	{
		while (*st != '\0' && *st == c)
			st++;
		if (*st != '\0')
			result[i++] = fill(st, c);
		if (!result[i - 1])
			return (free_all(result, i));
		while (*st && !(*st == c))
			st++;
	}
	result[i] = 0;
	return ((char **)result);
}
