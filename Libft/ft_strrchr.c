/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 03:40:59 by eun               #+#    #+#             */
/*   Updated: 2023/10/10 04:00:42 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	*str;

	len = ft_strlen(s) + 1;
	str = (unsigned char *)s;
	str += len - 1;
	while (len--)
	{
		if ((unsigned char)c == *str)
			return ((char *)str);
		str--;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}
