/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:49:54 by anleclab          #+#    #+#             */
/*   Updated: 2018/11/21 15:57:12 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

char	*ft_strdeljoin(char **dst, char **src)
{
	char	*res;

	res = ft_strjoin(*dst, *src);
	ft_strdel(dst);
	ft_strdel(src);
	return (res);
}

int		ft_read_protec(const int fd, char **buf)
{
	int		res;

	res = read(fd, *buf, BUFF_SIZE);
	if (res == -1)
		ft_strdel(buf);
	return (res);
}

char	*ft_trimline(char **str, int index)
{
	char	*res;

	if ((*str)[index] == '\n')
	{
		if (!(res = ft_strdup(*str + index + 1)) || !*res)
		{
			if (res && !*res)
				free(res);
			ft_strdel(str);
			return (NULL);
		}
		ft_strdel(str);
		return (res);
	}
	ft_strdel(str);
	return (NULL);
}

int		ft_addnextread(int fd, char **buf)
{
	char	*temp;
	int		readchar;

	if (!(temp = ft_strnew(BUFF_SIZE + 1))
			|| (readchar = ft_read_protec(fd, &temp)) == -1)
	{
		ft_strdel(buf);
		return (-1);
	}
	if (readchar)
		if (!(*buf = ft_strdeljoin(buf, &temp)))
			return (-1);
	return (readchar);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buf;
	int			i;
	int			readchar;

	readchar = -1;
	if (!buf)
		if (!(buf = ft_strnew(BUFF_SIZE + 1))
				|| (readchar = ft_read_protec(fd, &buf)) == -1)
			return (-1);
	i = -1;
	while ((buf[++i] || readchar) && buf[i] != '\n')
		if (!buf[i])
		{
			if ((readchar = ft_addnextread(fd, &buf)) == -1)
				return (-1);
			i--;
		}
	*line = NULL;
	if (i || buf[i] == '\n')
	{
		*line = (buf[i] == '\n' ? ft_strsub(buf, 0, i) : ft_strdup(buf));
		buf = ft_trimline(&buf, i);
		return (1);
	}
	return (0);
}
