/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:58:57 by donson            #+#    #+#             */
/*   Updated: 2023/10/25 14:28:27 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	result = (char *)malloc(len + 1 * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, len + 1);
	result[len] = '\0';
	if (!result)
		return (NULL);
	return (result);
}
