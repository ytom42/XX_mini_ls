#include "ft_mini_ls.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void ft_strlcpy(char *dst, char *src, int size)
{
	int i;

	i = 0;
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char *ft_strdup(char *str)
{
	int len;
	char *ptr;

	len = ft_strlen(str);
	ptr = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(ptr, str, len);
	return (ptr);
}

int check(t_file *lst, t_file *new)
{
	if (lst->sec == new->sec)
	{
		if (lst->nsec > new->nsec)
			return (1);
	}
	if (lst->sec > new->sec)
		return (1);
	return (0);
}

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
	if ((check(lst, new)))
	{
		new->next = lst;
		return (new);
	}
	first = lst;
	back = lst;
	lst = lst->next;
	while (lst)
	{
		if ((check(lst, new)))
		{
			back->next = new;
			new->next = lst;
			return (first);
		}
		back = lst;
		lst = lst->next;
	}
	back->next = new;
	return (first);
}