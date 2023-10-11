/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:58:57 by donson            #+#    #+#             */
/*   Updated: 2023/10/11 19:14:07 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_dynamic(char const *s, unsigned int start, size_t len)
{
	char	*result;

	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (!result)
	{
		free(result);
		return (NULL);
	}
	ft_memmove(result, s + start, len);
	result[len] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*result;

	s_len = ft_strlen(s);
	if (start + len <= s_len)
	{
		result = ft_substr_dynamic(s, start, len);
		return (result);
	}
	else if (start < s_len && len <= s_len)
	{
		len -= start + len - s_len;
		result = ft_substr_dynamic(s, start, len);
		return (result);
	}
	else
	{
		result = (char *)ft_calloc(1, 1);
		if (!result)
		{
			free(result);
			return (NULL);
		}
		return (result);
	}
}
