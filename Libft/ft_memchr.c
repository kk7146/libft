/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:14:55 by donson            #+#    #+#             */
/*   Updated: 2023/10/11 16:32:43 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_temp;

	s_temp = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if ((unsigned char)c == (unsigned char)*s_temp)
			return ((void *)s_temp);
		s_temp++;
	}
	return (NULL);
}
