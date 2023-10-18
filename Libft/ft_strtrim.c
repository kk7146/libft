/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:45:10 by eun               #+#    #+#             */
/*   Updated: 2023/10/18 11:19:33 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	result = NULL;
	if (s1 && set)
	{
		start = 0;
		end = ft_strlen(s1);
		while (ft_strchr(set, s1[start]) && s1[start] != 0)
		{
			if (start == end)
				return (ft_strdup(""));
			start++;
		}
		while (ft_strrchr(set, s1[end]) && end != 0)
		{
			if (start == end)
				return (ft_strdup(""));
			end--;
		}
		result = ft_substr(s1, start, end - start + 1);
	}
	return (result);
}
