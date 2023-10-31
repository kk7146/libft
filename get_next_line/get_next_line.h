/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donson <donson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:12:43 by donson            #+#    #+#             */
/*   Updated: 2023/10/31 17:33:07 by donson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42
# define FD_SIZE 1042

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

void	ft_lstadd_back(t_list_line **lst, t_list_line *new);
int		ft_split_gnl_resolve(t_list_line **result, char *s, char c);
char	*ft_strjoin(char *s1, char *s2);

#endif