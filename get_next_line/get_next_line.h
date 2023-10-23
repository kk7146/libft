/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:12:43 by donson            #+#    #+#             */
/*   Updated: 2023/10/19 17:55:47 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list_line
{
	void				*content;
	struct s_list_line	*next;
}	t_list_line;

typedef struct s_list_fd
{
	int					fd;
	struct s_list_line	*line;
	struct s_list_fd	*next;
}	t_list_fd;

char	*get_next_line(int fd);

#endif