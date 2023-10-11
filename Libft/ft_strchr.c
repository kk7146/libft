/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:26:25 by eun               #+#    #+#             */
/*   Updated: 2023/10/11 16:26:54 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if ((unsigned char)c == (unsigned char)*s)
			return ((char *)s);
		if ((unsigned char)*s == '\0')
			break ;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
