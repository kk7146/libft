/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:00 by eun               #+#    #+#             */
/*   Updated: 2023/10/23 12:51:42 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*new_line_node(t_list_line *data, int fd)
{
	size_t	i;
	int		size;
	char	*buf;
	char	*buf_buf;

	i = 0
	while (i++)
	{
		if (buf != NULL)
		{
			buf_buf = buf;
			free(buf);
		}
		buf = malloc(((BUFFER_SIZE * i) + 1) * sizeof(char));
		if (!buf)
			return (NULL);
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
		{
			free(buf);
			return (NULL);
		}
		else
		{
			if (!size)
		}
	}
	return (return_line());
}

static char	*return_line(t_list_line **data, int fd)
{
	char	*content_buf;

	if (*data)
	{
		content_buf = (*data)->content;
		data = (*data)->next;
		free(*data);
		return (content_buf);
	}
	else
		return (new_line_node(data, fd));
}

char	*get_next_line(int fd)
{
	static t_list_fd	*data;
	t_list_fd			*data_buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	data_buf = data;
	while (data_buf->fd != fd && data_buf != NULL)
		data_buf = data_buf->next;
	if (!data_buf)
	{
		data_buf = (t_list_fd *)malloc(sizeof(t_list_fd));
		if (!data_buf)
			return (NULL);
		data_buf->fd = fd;
		data_buf->line = NULL;
		data_buf->next = NULL;
	}
	return (return_line(data_buf->line, data_buf->fd));
}
