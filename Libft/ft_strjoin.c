/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:14:43 by donson            #+#    #+#             */
/*   Updated: 2023/10/11 20:02:06 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return ((void *)calloc(1, 1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_memmove(result, s1, len_s1);
	ft_memmove(result + len_s1, s2, len_s2);
	result[len_s1 + len_s2] = '\0';
	return (result);
}
