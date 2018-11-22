/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:40:04 by anleclab          #+#    #+#             */
/*   Updated: 2018/11/22 14:18:38 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		*fd;
	char	*line;
	char	*ret;
	int		i;
	int		j;
	char	*strfd;

	if (argc < 2)
	{
		write(1, "Use get_next_line instead, please.\n", 35);
		return (1);
	}
	if (!(fd = (int *)malloc(sizeof(int) * (argc - 1))))
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		if (fd[i] == -1)
		{
			write(1, "Error: open failed.\n", 20);
			free(fd);
			return (1);
		}
		i++;
	}
	line = NULL;
	i = 0;
	j = 0;
	while(i < 10)
	{
		while (j < argc - 1)
		{
			ret = ft_itoa(get_next_line_multiplefd(fd[j], &line));
			if (ft_strequ(ret, "-1"))
			{
				write(2, "Error: get_next_line failed.\n", 29);
				return (1);
			}
			write(1, ret, ft_strlen(ret));
			free(ret);
			strfd = ft_itoa(fd[j]);
			write(1, " (", 2);
			write(1, strfd, ft_strlen(strfd));
			free(strfd);
			write(1, ") : ", 4);
			if (line)
				write(1, line, strlen(line));
			write(1, "\n", 1);
			free(line);
			line = NULL;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		close(fd[i]);
		i++;
	}
	free(fd);
	return (0);
}
