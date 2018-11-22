/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:49:54 by anleclab          #+#    #+#             */
/*   Updated: 2018/11/22 14:18:40 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

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

int		get_next_line_multiplefd(const int fd, char **line)
{
	static char	*buf[1024];
	int			i;
	int			readchar;

	readchar = -1;
	if (!(buf[fd]))
		if (!(buf[fd] = ft_strnew(BUFF_SIZE + 1))
				|| (readchar = ft_read_protec(fd, buf + fd) == -1))
			return (-1);
	i = -1;
	while ((buf[fd][++i] || readchar) && buf[fd][i] != '\n')
		if (!buf[fd][i])
		{
			if ((readchar = ft_addnextread(fd, buf + fd)) == -1)
				return (-1);
			i--;
		}
	if (i || buf[fd][i] == '\n')
	{
		*line = (buf[fd][i] == '\n' ? ft_strsub(buf[fd], 0, i) : ft_strdup(buf[fd]));
		buf[fd] = ft_trimline(buf + fd, i);
		return (1);
	}
	return (0);
}
