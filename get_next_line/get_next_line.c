/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:00 by eun               #+#    #+#             */
/*   Updated: 2023/10/30 11:28:49 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill(char *str, char charset)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	len = 0;
	while (str[len] != '\0' && !(str[len] == charset))
		len++;
	if (!str)
		return (NULL);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i <= len)
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

static t_list_line	*ft_split_getnextline(char *s, char c)
{
	t_list_line	*result;
	t_list_line	*new;

	while (*s != '\0' && *s == c)
	{
		new = (t_list_line *)malloc(sizeof(t_list_line));
		new->content = fill(s++, c);
		new->next = NULL;
		ft_lstadd_back(&result, new);
	}
	while (*s != '\0')
	{
		if (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			new = (t_list_line *)malloc(sizeof(t_list_line));
			new->content = fill(s, c);
			new->next = NULL;
			ft_lstadd_back(&result, new);
		}
		while (*s && !(*s == c))
			s++;
	}
	return (result);
}

static char	*return_line(t_list_fd *data, int fd)
{
	char		*buf;
	t_list_line	*list_buf;
	int			read_size;
	int			isTrue;

	isTrue = 0;
	while ()
	{
		isTrue = 1;
	}
	while (read_size != 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		ft_lstadd_back(data->line, ft_split_getnextline(buf));
	}
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
	return (return_line(data_buf, data_buf->fd));
}
