/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:12:43 by donson            #+#    #+#             */
/*   Updated: 2023/11/07 17:37:36 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_SIZE
#  define FD_SIZE 1042
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list_line
{
	char				*content;
	struct s_list_line	*next;
}	t_list_line;

typedef struct s_list_fd
{
	int					fd;
	struct t_list_line	*line;
	struct t_list_fd	*next;
}	t_list_fd;

int		ft_split_gnl_resolve(t_list_line **result, char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		read_buf(char **result, int fd);
int		ft_strchr_lst(t_list_line *lst, int c);
char	*get_next_line(int fd);

#endif