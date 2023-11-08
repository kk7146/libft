/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:00 by eun               #+#    #+#             */
/*   Updated: 2023/11/07 17:35:27 by eun              ###   ########.fr       */
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

char	*ft_str_return(t_list_line **lst)
{
	char		*result;
	t_list_line	*lst_buf;
	long long	len;
	long long	i;

	lst_buf = *lst;
	len = 0;
	while ((*lst)->content[len] != '\n' && (*lst)->content[len] != '\0')
		len++;
	result = (char *)malloc(((len + 1) * sizeof(char)));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len)
		result[i] = (*lst)->content[i];
	result[i] = '\0';
	free((*lst)->content);
	(*lst) = (*lst)->next;
	free(lst_buf);
	return (result);
}

char	*get_next_line(int fd)
{
	static t_list_line	*data[FD_SIZE];
	char				*buf;
	int					state;

	if (fd < 1 || fd > FD_SIZE || BUFFER_SIZE < 1)
		return (NULL);
	if (ft_strchr_lst(data[fd], '\n'))
		return (ft_str_return(&data[fd]));
	else
	{
		buf = (char *)malloc(1);
		buf[0] = 0;
		state = read_buf(&buf, fd);//0 - EOF인데 아무런 값도 읽지 못 했을 때 일단 값이 들어가긴 했을 때. -1 - 파일 읽기 오류 -2 널가드 터짐.
		if (state == -2 || state == -1)
		{
			free(buf);
			return (NULL);
		}
		else if (state == 0)
		{
			if (!data[fd])
			{
				free(buf);
				return (NULL);
			}
			return (ft_str_return(&data[fd]));
		}
		if (!ft_split_gnl_resolve(&data[fd], buf, '\n') && state == 1)
		{
			ft_lstclear(&data[fd]);
			free(buf);
			return (NULL);
		}
		free(buf);
		return (ft_str_return(&data[fd]));
	}
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
//	fd = open( "test", O_RDONLY);
//	while (1)
//	{
//		chr = get_next_line(fd);
//		if (chr == NULL)
//			break ;
//		printf("%s\n", chr);
//		free(chr);
//	}
//	close(fd);
//	atexit(check_leak);
//	return (0);
//}
