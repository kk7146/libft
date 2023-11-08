/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:00 by eun               #+#    #+#             */
/*   Updated: 2023/11/08 18:23:09 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_lst_clear(t_list_line **lst, char *buf)
{
	t_list_line	*temp;

	while (lst && *lst)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	free(buf);
	return (NULL);
}

static	char	*ft_str_return(t_list_line **lst, char *buf)
{
	char		*result;
	t_list_line	*lst_buf;

	lst_buf = *lst;
	result = (*lst)->content;
	(*lst) = (*lst)->next;
	free(lst_buf);
	free(buf);
	return (result);
}

static	int	ft_split_gnl_resolve(t_list_line **result, char *s, char c)
{
	t_list_line	*new;

	if (*s != '\0' && *s == c)
	{
		new = fill(s, c);
		if (!split_fail_free(result, new))
			return (0);
	}
	while (*s != '\0')
	{
		if (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			new = fill(s, c);
			if (!split_fail_free(result, new))
				return (0);
		}
		while (*s && !(*s == c))
			s++;
	}
	return (1);
}

static	int	read_buf(char **result, int fd)
{
	int		read_size;
	char	buffer[BUFFER_SIZE + 1];
	size_t	i;
	size_t	j;

	j = 1;
	while (1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (j && !read_size)
			return (0);
		if (read_size == -1)
			return (-1);
		buffer[read_size] = '\0';
		*result = ft_strjoin(*result, buffer);
		if (!(*result))
			return (-2);
		i = 0;
		while ((*result)[i] != '\0')
			if ((*result)[i++] == '\n' || !read_size)
				return (1);
		j = 0;
	}
}

char	*get_next_line(int fd)
{
	static t_list_line	*data[FD_SIZE];
	char				*buf;
	int					state;

	if (fd < 0 || fd == 1 || fd == 2 || fd > FD_SIZE || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char));
	if (!buf)
		return (ft_lst_clear(&data[fd], buf));
	buf[0] = 0;
	state = ft_strchr_lst(data[fd], '\n');
	if (state == 1)
		return (ft_str_return(&data[fd], buf));
	if (state == -1)
		return (ft_lst_clear(&data[fd], buf));
	state = read_buf(&buf, fd);
	if (state == -2 || state == -1)
		return (ft_lst_clear(&data[fd], buf));
	else if (state == 0)
		if (!data[fd])
			return (ft_lst_clear(&data[fd], buf));
	if (!ft_split_gnl_resolve(&data[fd], buf, '\n'))
		return (ft_lst_clear(&data[fd], buf));
	return (ft_str_return(&data[fd], buf));
}

//#include <fcntl.h>
//
//void	check_leak(void)
//{
//	system("leaks a.out");
//}
//
//int main()
//{
//	int			fd;
//	char		*chr;
//
//	fd = open( "tests/test", O_RDONLY);
//	while (1)
//	{
//		chr = get_next_line(fd);
//		if (chr == NULL)
//			break ;
//		printf("%s", chr);
//		free(chr);
//	}
//	close(fd);
//	return (0);
//}
