/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:04 by eun               #+#    #+#             */
/*   Updated: 2023/11/08 18:22:38 by donson           ###   ########.fr       */
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
	if (!lst->content)
		return (-1);
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len[3];
	char	*s1_buf;
	char	*result;

	len[0] = 0;
	len[1] = 0;
	while (s1[len[0]] != '\0')
		len[0]++;
	while (s2[len[1]] != '\0')
		len[1]++;
	result = (char *)malloc(sizeof(char) * (len[0] + len[1]) + 1);
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	len[2] = 0;
	s1_buf = s1;
	while (*s1)
		result[len[2]++] = *s1++;
	while (*s2)
		result[len[2]++] = *s2++;
	result[len[2]] = '\0';
	free(s1_buf);
	return (result);
}

int	ft_lst_add_back(t_list_line **lst, t_list_line *new)
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
			if (!temp->content)
				return (0);
			free(new->content);
			free(new);
		}
	}
	else
		*lst = new;
	return (1);
}

t_list_line	*fill(char *str, char charset)
{
	int			len;
	t_list_line	*new;

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
	if (str[len] == charset)
		len++;
	new->content = (char *)malloc(sizeof(char) * (len + 1));
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	new->content[len] = '\0';
	while (len--)
		new->content[len] = str[len];
	return (new);
}

int	split_fail_free(t_list_line **result, t_list_line *new)
{
	if (!new)
		return (0);
	if (!ft_lst_add_back(result, new))
	{
		free(new->content);
		free(new);
		return (0);
	}
	return (1);
}
