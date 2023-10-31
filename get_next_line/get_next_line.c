/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:00 by eun               #+#    #+#             */
/*   Updated: 2023/10/31 18:15:40 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list_line **lst)
{
	t_list_line	*temp;

	while (lst && *lst)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if ((unsigned char)c == (unsigned char)*s)
			return ((char *)s);
		if ((unsigned char)*s == '\0')
			break ;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list_line	*data[FD_SIZE];
	char	*result;

	if (fd < 1 || fd > FD_SIZE || BUFFER_SIZE < 1)
		return (NULL);
	if (!data[fd] || !(*data[fd])->content)
	{
		if (!data[fd])
			data[fd] = (t_list_line *)malloc(sizeof(t_list_line));
		if (!data[fd])
			return (NULL);
		if (read_buf(&result, fd))
		{
			ft_lstclear(&data[fd]);
			return (NULL);
		}
		else
			return(EOF());
		if (!ft_split_gnl_resolve(&data[fd], result, '\n'))
		{
			ft_lstclear(&data[fd]);
			return (NULL);
		}
	}
	if (!(*data[fd])->content)
	{
		
	}
	if (!ft_strchr((*data[fd])->content))
	{

	}
	else
	{
		
	}
}
int main()
{
	static t_list_line	*data[FD_SIZE];
}