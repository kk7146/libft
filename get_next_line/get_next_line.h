/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eun <eun@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:12:43 by donson            #+#    #+#             */
/*   Updated: 2023/10/26 17:19:11 by eun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list_fd
{
	int					fd;
	char				*content;
	char				*content_add;
	struct s_list_fd	*next;
}	t_list_fd;

char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t d_size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, char c, int *index);
char	*ft_strdup(const char *s1);

#endif