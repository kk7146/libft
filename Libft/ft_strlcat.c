/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:19:46 by donson            #+#    #+#             */
/*   Updated: 2023/10/09 20:31:39 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t d_size)
{
	size_t	i;
	size_t	len;
	size_t	len_s;

	i = 0;
	len = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (d_size <= len || d_size == 0)
		return (len_s + d_size);
	while (src[i] != '\0' && d_size - 1 > len + i)
	{
		dst[len + i] = src [i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + len_s);
}
