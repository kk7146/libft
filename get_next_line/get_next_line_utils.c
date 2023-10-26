/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:04 by eun               #+#    #+#             */
/*   Updated: 2023/10/26 17:50:33 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t d_size)
{
	unsigned int	i;
	unsigned int	srclen;

	i = 0;
	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (d_size != 0)
	{
		while (i < d_size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
		return (srclen);
	dst[i] = '\0';
	return (srclen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	while ((unsigned char)s1[len_s1] != '\0')
		len_s1++;
	while ((unsigned char)s1[len_s2] != '\0')
		len_s2++;
	len_s2 = 0;
	while (s2[len_s2] != '\0')
		len_s2++;
	result = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len_s1 + 1);
	ft_strlcpy(result + len_s1, s2, len_s2 + 1);
	return (result);
}

char	*ft_strchr(const char *s, char c, int *index)
{
	*index = 0;
	while (1)
	{
		if ((unsigned char)c == (unsigned char)*s)
			return ((char *)s);
		if ((unsigned char)*s == '\0')
			break ;
		s++;
		(*index)++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
	return ((char *)index);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;

	if (!(*s1))
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	len = 0;
	while (s1[len] != '\0')
		len++;
	str = (char *)malloc(((len + 1) * sizeof(char)));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}
