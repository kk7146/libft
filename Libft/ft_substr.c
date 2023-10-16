/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:58:57 by donson            #+#    #+#             */
/*   Updated: 2023/10/16 11:36:36 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_dynamic(char const *s, unsigned int start, size_t len)
{
	char	*result;

	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_memmove(result, s + start, len);
	result[len] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*result;

	s_len = ft_strlen(s);
	if (start > s_len)
	{
		result = malloc(sizeof(char));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (s_len - start < len)
		len -= start + len - s_len;
	result = ft_substr_dynamic(s, start, len);
	if (!result)
		return (NULL);
	return (result);
}
