/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:00 by eun               #+#    #+#             */
/*   Updated: 2023/10/31 16:14:52 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list_fd	*head;
	t_list_fd			*data;
	t_list_fd			*head_buf;

	if (fd < 1 || fd > FD_SIZE || BUFFER_SIZE < 1)
		return (NULL);
	if (!head)
	{
		
	}
	while (data_buf && data_buf->fd != fd)
		data_buf = data_buf->next;
	if (!data_buf)
	{
		data_buf = (t_list_fd *)malloc(sizeof(t_list_fd));
		if (!data_buf)
			return (NULL);
		data_buf->line-> = NULL;
		data->next = data_buf;
	}

}
int main()
{
	
}