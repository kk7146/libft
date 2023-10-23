/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:04 by eun               #+#    #+#             */
/*   Updated: 2023/10/23 12:44:18 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
		if(str[i] != '\0')
			count++;
		while (str[i] != '\0' && !(str[i] == charset))
			i++;
	}
	return (count);
}

static char	*fill(char *str, char charset)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	len = 0;
	while (str[len] != '\0' && !(str[len] == charset))
		len++;
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

char	**ft_split_getnextline(char const *s, char c)
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

void	check_leak(void)
{
	system("leaks a.out");
}

int	main()
{
	char	*c = "aaaa\naaaaa\naaaaa\n\n";
	char	**chr;

	chr = ft_split_getnextline(c, '\n');
	for (size_t i = 0; chr[i] != NULL; i++)
		printf("%s\n", chr[i]);
	for (size_t i = 0; chr[i] != NULL; i++)
		free(chr[i]);
	free(chr);
	atexit(check_leak);
	return (0);
}
