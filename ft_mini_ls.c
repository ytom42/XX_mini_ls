#include "ft_mini_ls.h"

int main()
{
	DIR *dir;
	struct dirent *dent;
	struct stat buf;
	t_file *ptr;
	t_file *lst;

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
	}
	closedir(dir);
	free(ptr);
}
