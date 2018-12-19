# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anleclab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 17:09:00 by anleclab          #+#    #+#              #
#    Updated: 2018/12/19 17:34:08 by anleclab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

all: single

single: libft/libft.a
	gcc -Wall -Wextra -Werror -L./libft -lft main.c get_next_line.c -o $(NAME)

multiple: libft/libft.a
	gcc -Wall -Wextra -Werror -L./libft -lft main_multiple_fd.c \
		get_next_line_multiplefd.c -o $(NAME)

libft/libft.a:
	make -C libft
	make -C libft clean

clean: fclean

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all single multiple clean fclean re
