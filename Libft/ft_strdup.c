/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:40:11 by donson            #+#    #+#             */
/*   Updated: 2023/10/11 17:44:20 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;

	if (!(*s1))
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
		{
			free(str);
			return (NULL);
		}
		*str = '\0';
		return (str);
	}
	len = ft_strlen(s1);
	str = (char *)malloc(((len + 1) * sizeof(char)));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(str, s1, len + 1);
	return (str);
}
