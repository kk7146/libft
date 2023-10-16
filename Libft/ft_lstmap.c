/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:07:12 by eun               #+#    #+#             */
/*   Updated: 2023/10/16 18:53:40 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		size;
	t_list	*new;
	t_list	*new_node_first;

	new_node_first = NULL;
	size = ft_lstsize(lst);
	while (size--)
	{
		new = ft_lstnew((*f)(lst->content));
		lst = lst->next;
		if (!new)
		{
			ft_lstclear(&new_node_first, del);
			return (NULL);
		}
		ft_lstadd_back(&new_node_first, new);
	}
	return (new_node_first);
}
