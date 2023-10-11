/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:35:14 by donson            #+#    #+#             */
/*   Updated: 2023/10/11 16:35:26 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	if (!*haystack)
		return (NULL);
	while (len > 0)
	{
		if (*haystack == *needle && *haystack != '\0' && *needle != '\0')
		{
			i = 1;
			while (*(needle + i) == *(haystack + i) && len != i
				&& *(needle + i) != '\0' && *(haystack + i) != '\0')
				i++;
			if (len_needle == i)
				return ((char *)haystack);
		}
		if (*haystack != '\0')
			haystack++;
		len--;
	}
	return (NULL);
}
