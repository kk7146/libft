/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:59:08 by donson            #+#    #+#             */
/*   Updated: 2023/10/18 16:15:07 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_isspace(char c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long int	num;
	long long		temp;
	int				i;
	int				sign;

	num = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		temp = num;
		num = num * 10 + (str[i] - '0');
		if (num < temp && sign == 1)
			return (-1);
		else if (num < temp && sign == -1)
			return (0);
		i++;
	}
	return ((int)((long long int)sign * num));
}
