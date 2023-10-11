/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:59:08 by donson            #+#    #+#             */
/*   Updated: 2023/10/11 16:02:45 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(unsigned char c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				i;
	int				sign;
	unsigned char	*st;

	st = (unsigned char *)str;
	num = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(st[i]))
		i++;
	if (st[i] == '-' || st[i] == '+')
	{
		if (st[i] == '-')
			sign = -1;
		i++;
	}
	while (st[i] != '\0' && (st[i] >= '0' && st[i] <= '9'))
	{
		num = num * 10 + (st[i] - '0');
		i++;
	}
	return (sign * num);
}
