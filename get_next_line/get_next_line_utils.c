/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:04 by eun               #+#    #+#             */
/*   Updated: 2023/10/26 13:25:38 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list_line **lst, t_list_line *new)
{
	t_list_line	*temp;

	if (*lst)
	{
		temp = *lst;
		while (temp)
		{
			if (!temp->next)
				break ;
			temp = temp->next;
		}
		temp->next = new;
	}
	else
		*lst = new;
}

