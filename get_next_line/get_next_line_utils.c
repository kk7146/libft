/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:04 by eun               #+#    #+#             */
/*   Updated: 2023/10/31 16:14:07 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_lst_add_back(t_list_line **lst, t_list_line *new)
{
	t_list_line	*temp;

	if (*lst)
	{
		temp = *lst;
		while (temp)
		{
			if (!temp->next)
				break ;
			temp = temp->next;
		}
		temp->next = new;
	}
	else
		*lst = new;
}

static t_list_line	*fill(char *str, char charset)
{
	int			len;
	int			i;
	t_list_line	*new;

	i = 0;
	len = 0;
	if (!str)
		return (NULL);
	new = (t_list_line *)malloc(sizeof(t_list_line));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = NULL;
	while (str[len] != '\0' && !(str[len] == charset))
		len++;
	new->content = (char *)malloc(sizeof(char) * (len + 1));
	if (!new->content)
		return (NULL);
	while (i <= len)
	{
		new->content[i] = str[i];
		i++;
	}
	return (new);
}

int	ft_split_gnl_resolve(t_list_line **result, char *s, char c)//return 값은 오류코드. 
{
	t_list_line	*new;

	if (*s != '\0' && *s == c)
	{
		new = fill(s, c);
			if (!new)
				return (0);
			ft_lst_add_back(result, new);
	}
	while (*s != '\0')
	{
		if (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			new = fill(s, c);
			if (!new)
				return (0);
			ft_lst_add_back(result, new);
		}
		while (*s && !(*s == c))
			s++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[s2_len] != '\0')
		s2_len++;
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

int	read_buf(int fd, char **result)
{
	int		read_size;
	char	buffer[BUFFER_SIZE];
	size_t	i;

	read_size = 1;
	while (1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 1)
			return (read_size);
			buffer[read_size] = '\0';
		*result = ft_strjoin(*result, buffer);
		if (!(*result))
			return (-2);
		i = 0;
		while ((*result)[i] != '\0')
			if ((*result)[i++] == '\n')
				return (1);
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
//	char	*result;
//	int		fd;
//
//	fd = open( "test", O_RDONLY);
//	read_buf(fd, &result);
//	printf("%s\n", result);
//	printf("--------------------------------\n");
//	free(result);
//	read_buf(fd, &result);
//	printf("%s", result);
//	free(result);
//	close(fd);
//	return 0;
//}

//void	ft_lstclear(t_list_line **lst)
//{
//	t_list_line	*temp;
//
//	while (lst && *lst)
//	{
//		temp = (*lst)->next;
//		free((*lst)->content);
//		free(*lst);
//		*lst = temp;
//	}
//}
//
//void	check_leak(void)
//{
//	system("leaks a.out");
//}
//
//int main()
//{
//	char		*chr = "\n1\n2\n3\n4\n5\n";
//	t_list_line	*lst;
//	t_list_line	*temp;
//
//	ft_split_gnl_resolve(&lst, chr, '\n');
//	temp = lst;
//	while (temp != NULL)
//	{
//		printf("start%send\n", temp->content);
//		temp = temp->next;
//	}
//	ft_lstclear(&lst);
//	return (0);
//}
