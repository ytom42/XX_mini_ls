/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 10:54:53 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/12/04 21:49:07 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>
# include <string.h>

typedef struct		s_file
{
	char			name[1024];
	int				len;
	long			sec;
	long			nsec;
	struct s_file	*next;
}					t_file;

void				ft_strlcpy(char *dst, char *src, int size);
int					ft_strlen(char *str);
int					check(t_file *lst, t_file *new);
t_file				*ft_lstnew(char *name, int len, struct stat *buf);
t_file				*ft_sort(t_file *lst, t_file *new);

#endif
