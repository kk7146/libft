/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:00 by eun               #+#    #+#             */
/*   Updated: 2023/11/06 14:47:32 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_lst(t_list_line *lst, int c)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
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

char	*ft_str_return(t_list_line **lst)//working on
{
	char		*result;
	t_list_line	*lst_buf;
	int			i;

	lst_buf = *lst;
	result = (*lst)->content;
	(*lst) = (*lst)->next;
	free(lst_buf);

	i = 0;
	while ((unsigned char)s[i] != '\0')
		i++;
	return (result);
}

//char	*get_next_line(int fd)
//{
//	static t_list_line	*data[FD_SIZE];
//	char				*buf;
//
//	if (fd < 1 || fd > FD_SIZE || BUFFER_SIZE < 1)
//		return (NULL);
//	if ((ft_strchr_lst(lst, '\n')))
//	{
//		if (!(*data[fd]))
//		{
//			*data[fd] = (t_list_line *)malloc(t_list_line);
//			*data[fd]->content = (char *)malloc(1);
//			*data[fd]->content[0] = 0;
//		}
//		read_buf(&buf, fd);
//		ft_split_gnl_resolve(&data[fd], buf, '\n')
//		if (ft_strchr_lst(&data[fd], '\n'))
//			return(ft_str_return(&data[fd]));
//	}
//}
#include <fcntl.h>

void	check_leak(void)
{
	system("leaks a.out");
}

int main()
{
	char		*chr;
	t_list_line	*lst;
	int			fd;

	chr = (char *)malloc(1);
	chr[0] = 0;
	fd = open( "test", O_RDONLY);
	lst = (t_list_line *)malloc(sizeof(t_list_line));
	lst->content = (char *)malloc(2);
	lst->content[0] = 'a';
	lst->content[1] = 0;
	read_buf(&chr, fd);
	ft_split_gnl_resolve(&lst, chr, '\n');
	free(chr);
	if (ft_strchr_lst(lst, '\n'))
	{
		printf("sucess\n");
		chr = ft_str_return(&lst);
		printf("%s", chr);
		free(chr);
		chr = ft_str_return(&lst);
		printf("%s", chr);
		free(chr);
	}
	else
		printf("fail");
	ft_lstclear(&lst);
	close(fd);
	atexit(check_leak);
	return (0);
}
