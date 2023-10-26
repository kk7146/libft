/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:00 by eun               #+#    #+#             */
/*   Updated: 2023/10/26 17:29:43 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*result_eof(t_list_fd *lst)
{
	char	*result;

	result = ft_strdup(lst->content);
	free(lst->content_add);
	lst->content_add = NULL;
	lst->content = NULL;
	return (result);
}

static char	*return_line(t_list_fd *lst)
{
	int		read_size;
	char	*result;
	char	buf[BUFFER_SIZE + 1];
	int		index;

	if (!lst->content)
	{
		read_size = read(lst->fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		buf[read_size] = '\0';
		lst->content = ft_strdup(buf);
		if (!lst->content)
			return (NULL);
		return (return_line(lst));
	}
	if (!ft_strchr(lst->content, '\n', &index))
	{
		read_size = read(lst->fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		if (read_size == 0)
			return (result_eof(lst));
		buf[read_size] = '\0';
		result = ft_strjoin(lst->content, buf);
		if (!result)
			return (NULL);
		free(lst->content);
		lst->content = result;
		return (return_line(lst));
	}
	else
	{
		lst->content[index] = '\0';
		result = ft_strdup(lst->content);
		if (!result)
			return (NULL);
		lst->content += index + 1;
		return (result);
	}
}

char	*get_next_line(int fd)
{
	static t_list_fd	*data;
	t_list_fd			*data_buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	data_buf = data;
	while (data_buf != NULL && data_buf->fd != fd)
		data_buf = data_buf->next;
	if (!data_buf)
	{
		data_buf = (t_list_fd *)malloc(sizeof(t_list_fd));
		if (!data_buf)
			return (NULL);
		data_buf->fd = fd;
		data_buf->content = NULL;
		data_buf->next = NULL;
	}
	return (return_line(data_buf));
}
