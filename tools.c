/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 10:54:49 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/12/04 11:05:56 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, char *src, int size)
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

int		check(t_file *lst, t_file *new)
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
