/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:12:43 by donson            #+#    #+#             */
/*   Updated: 2023/11/08 14:12:30 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

int		ft_split_gnl_resolve(t_list_line **result, char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		read_buf(char **result, int fd);
int		ft_strchr_lst(t_list_line *lst, int c);
char	*get_next_line(int fd);

#endif