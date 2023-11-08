/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:00 by eun               #+#    #+#             */
/*   Updated: 2023/11/08 14:23:23 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_lst(t_list_line *lst, int c)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	if (!lst->content)
		lst->content = ((char *)malloc(sizeof(char)));
	while (lst)
	{
		while (1)
		{
			if (c == lst->content[i])
				return (1);
			if (lst->content[i] == '\0')
				break ;
			i++;
		}
		i = 0;
		lst = lst->next;
	}
	if (c == '\0')
		return (0);
	return (0);
}

char	*ft_lstclear(t_list_line **lst, char *buf)
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

char	*ft_str_return(t_list_line **lst, char *buf)
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

char	*get_next_line(int fd)
{
	static t_list_line	*data[FD_SIZE];
	char				*buf;
	int					state;

	if (fd < 0 || fd == 1 || fd == 2 || fd > FD_SIZE || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	if (ft_strchr_lst(data[fd], '\n'))
		return (ft_str_return(&data[fd], buf));
	state = read_buf(&buf, fd);
	if (state == -2 || state == -1)
		return (ft_lstclear(&data[fd], buf));
	else if (state == 0)
	{
		if (!data[fd])
			return (ft_lstclear(&data[fd], buf));
		return (ft_str_return(&data[fd], buf));
	}
	if (!ft_split_gnl_resolve(&data[fd], buf, '\n') && state == 1)
		return (ft_lstclear(&data[fd], buf));
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
