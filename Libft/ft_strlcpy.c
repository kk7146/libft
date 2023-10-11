/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:13:20 by donson            #+#    #+#             */
/*   Updated: 2023/10/09 20:17:54 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *src, size_t d_size)
{
	unsigned int	i;
	unsigned int	srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (d_size != 0)
	{
		while (i < d_size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		return (srclen);
	}
	dst[i] = '\0';
	return (srclen);
}
