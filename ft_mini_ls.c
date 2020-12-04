/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 10:54:55 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/12/04 21:29:34 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

t_file	*ft_lstnew(char *name, int len, struct stat *buf)
{
	t_file *ptr;

	ptr = malloc(sizeof(t_file));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr->name, name, len);
	ptr->len = len;
	ptr->sec = buf->st_mtimespec.tv_sec;
	ptr->nsec = buf->st_mtimespec.tv_nsec;
	ptr->next = NULL;
	return (ptr);
}

t_file	*ft_sort(t_file *lst, t_file *new)
{
	t_file *first;
	t_file *back;

	if (lst == NULL)
		return (new);
	first = lst;
	back = NULL;
	while (lst)
	{
		if ((check(lst, new)))
		{
			new->next = lst;
			if (back == NULL)
				return (new);
			else
			{
				back->next = new;
				return (first);
			}
		}
		back = lst;
		lst = lst->next;
	}
	back->next = new;
	return (first);
}

int		main(void)
{
	DIR				*dir;
	struct dirent	*dent;
	struct stat		buf;
	t_file			*ptr;
	t_file			*lst;

	lst = NULL;
	dir = opendir("./");
	while ((dent = readdir(dir)) != NULL)
	{
		if (dent->d_name[0] == '.')
			continue ;
		lstat(dent->d_name, &buf);
		ptr = ft_lstnew(dent->d_name, dent->d_namlen, &buf);
		lst = ft_sort(lst, ptr);
	}
	while (lst)
	{
		write(1, lst->name, lst->len);
		write(1, "\n", 1);
		ptr = lst;
		lst = lst->next;
		free(ptr);
	}
	closedir(dir);
}
