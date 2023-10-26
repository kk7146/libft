/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:00 by eun               #+#    #+#             */
/*   Updated: 2023/10/26 20:11:53 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*result_eof(t_list_fd *lst)
{
	char	*result;

	result = ft_strdup(lst->content);
	lst->head->next = lst->next;
	lst->next->head = lst->head;
	free(lst->content_add);
	free(lst);
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
	static t_list_fd	*data_buf;
	t_list_fd			*tail;
	t_list_fd			*head;
	char				*cha;

	cha = NULL;
	if (fd <= 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!data_buf)
	{
		tail = (t_list_fd *)malloc(sizeof(t_list_fd));
		if (!tail)
			return (NULL);
		head = (t_list_fd *)malloc(sizeof(t_list_fd));
		if (!head)
			return (NULL);
		tail->head = head;
		tail->next = NULL;
		head->head = NULL;
		head->next = tail;
	}
	while (data_buf != NULL && data_buf->fd != fd)
		data_buf = data_buf->next;
	if (!data_buf)
	{
		data_buf = (t_list_fd *)malloc(sizeof(t_list_fd));
		if (!data_buf)
			return (NULL);
		data_buf->fd = fd;
		data_buf->content = NULL;
		data_buf->next = tail;
		data_buf->head = tail->head;
		data_buf->next->head = data_buf;
	}
	return (return_line(data_buf));
}
#include <fcntl.h>

int main()
{
	int a;
	int i = 0;
	a = open("test", O_RDONLY);

	while (i < 13)
	{
		printf("%s\n", get_next_line(a));
		i++;
	}
	close(a);
}