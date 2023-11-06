/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:04 by eun               #+#    #+#             */
/*   Updated: 2023/11/06 14:21:56 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*s1_buf;
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
	s1_buf = s1;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	free(s1_buf);
	return (result);
}

int	read_buf(char **result, int fd)
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
			return (-1);
		i = 0;
		while ((*result)[i] != '\0')
			if ((*result)[i++] == '\n')
				return (1);
	}
}

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
		if (ft_strchr_lst(*lst, '\n'))
			temp->next = new;
		else
		{
			temp->content = ft_strjoin(temp->content, new->content);
			free(new->content);
			free(new);
		}
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

int	ft_split_gnl_resolve(t_list_line **result, char *s, char c)
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
