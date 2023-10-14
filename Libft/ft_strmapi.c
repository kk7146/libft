/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:53:43 by eun               #+#    #+#             */
/*   Updated: 2023/10/14 14:42:16 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	*string;
	size_t			len;
	size_t			i;

	len = ft_strlen(s);
	string = (unsigned char *)ft_calloc(len + 1, sizeof(unsigned char));
	if (!string)
		return (NULL);
	i = 0;
	while (i++ < len)
		string[i - 1] = f(i - 1, s[i - 1]);
	string[len] = 0;
	return ((char *)string);
}
