/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:51:44 by eun               #+#    #+#             */
/*   Updated: 2023/10/16 12:01:09 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(unsigned char *str, unsigned char charset)
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

static int	len_word(unsigned char *str, unsigned char charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !(str[i] == charset))
		i++;
	return (i);
}

static unsigned char	*fill(unsigned char *str, unsigned char charset)
{
	int				len;
	int				i;
	unsigned char	*word;

	i = 0;
	len = len_word(str, charset);
	word = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_all(unsigned char	**result, int i)
{
	while (i)
		free(result[--i]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	unsigned char	**result;
	unsigned char	*st;
	int				i;

	if (s == 0)
		return (0);
	st = (unsigned char *)s;
	i = count_word(st, c) + 1;
	result = (unsigned char **)malloc(i * (sizeof(unsigned char *)));
	if ((!result) || i == 1)
		return (NULL);
	i = 0;
	while (*st != '\0')
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
