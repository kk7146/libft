/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:12:14 by eun               #+#    #+#             */
/*   Updated: 2023/10/12 18:11:55 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int nbr, int *sign)
{
	long long int	nb;
	int				len;

	len = 0;
	nb = (long long int)nbr;
	*sign = 0;
	if (nbr < 0)
	{
		nb *= -1;
		*sign = 1;
		len++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	len++;
	return (len);
}

static unsigned char	*ft_itoa_set_chr(size_t len, int n)
{
	unsigned char	*chr;
	long			num;

	chr = (unsigned char *)ft_calloc((len + 1), sizeof(unsigned char));
	if (!chr)
		return (NULL);
	num = (long)n;
	chr[len] = '\0';
	while (--len + 1)
	{
		if (num < 0)
		{
			num *= -1;
			chr++;
			chr[-1] = '-';
		}
		else if (num < 10)
			chr[len] = num + '0';
		else
		{
			chr[len] = (num % 10) + '0';
			num /= 10;
		}
	}
	return (chr);
}

char	*ft_itoa(int n)
{
	size_t			len;
	unsigned char	*chr;
	int				sign;

	len = ft_itoa_len(n, &sign);
	chr = ft_itoa_set_chr(len, n);
	if (!chr)
		return (NULL);
	if (sign)
		chr--;
	return ((char *)chr);
}
