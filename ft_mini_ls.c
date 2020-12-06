/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 10:54:55 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/12/06 15:16:20 by ytomiyos         ###   ########.fr       */
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

t_file	*put_list(t_file *lst)
{
	t_file *tmp;

	write(1, lst->name, lst->len);
	write(1, "\n", 1);
	tmp = lst;
	lst = lst->next;
	free(tmp);
	return (lst);
}

int		main(int ac, char **av)
{
	DIR				*dir;
	t_file			*ptr;
	t_file			*lst;
	struct dirent	*dent;
	struct stat		buf;

	if (ac != 1)
	{
		write(1, "Command line arguments are not allowed.\n", 41);
		return (1);
	}
	av = NULL;
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
		lst = put_list(lst);
	closedir(dir);
	return (0);
}
