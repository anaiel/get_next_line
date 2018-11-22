/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:40:04 by anleclab          #+#    #+#             */
/*   Updated: 2018/11/22 13:25:18 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	if (argc = 1)
		fd = 0;
	else if((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(2, "Error: Couldn't open file.\n", 27);
		return (1);
	}
	line = NULL;
	while((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret == -1)
		{
			write(2, "Error: get_next_line failed.\n", 29);
			return (1);
		}
		write(1, ft_itoa(ret), strlen(ft_itoa(ret)));
		write(1, " : ", 3);
		write(1, line, strlen(line));
		write(1, "\n", 1);
	}
	write(1, ft_itoa(ret), strlen(ft_itoa(ret)));
	write(1, " X\n", 3);
	free(line);
	close(fd);
	return (0);
}
