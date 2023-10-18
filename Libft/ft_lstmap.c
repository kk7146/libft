/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:07:12 by eun               #+#    #+#             */
/*   Updated: 2023/10/18 12:56:10 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_node_first;
	void	*new_content;

	new_node_first = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		new = ft_lstnew(new_content);
		if (!new)
		{
			del(new_content);
			ft_lstclear(&new_node_first, del);
			return (NULL);
		}
		ft_lstadd_back(&new_node_first, new);
		lst = lst->next;
	}
	return (new_node_first);
}
