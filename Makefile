# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 09:14:19 by dtrigalo          #+#    #+#              #
#    Updated: 2019/04/23 13:33:38 by anleclab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

CFLAGS = -Wall -Wextra -Werror
SRC = main.c \
	  get_next_line.c
SRCSFD = srcs/
OBJSFD = objs/
OBJS = $(addprefix $(OBJSFD),$(SRC:.c=.o))

HDR = get_next_line.h
HDRSFD = includes/
HDRS = $(addprefix $(HDRSFD),$(HDR))

HDR_INC = -I./includes
LIBFT_HDR = -I./libft/includes
LIB_BINARY = -L./libft -lft
LIBFT= libft/libft.a

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

all: check_libft project $(NAME) $(HDRS)
	@echo "Project ready"

$(NAME): $(OBJSFD) $(OBJS) $(LIBFT) $(HDRS)
	@gcc $(CFLAGS) $(OBJS) $(LIB_BINARY) -o $@
	@echo "\t[ \033[0;32m✔\033[0m ] $(NAME) executable"

check_libft:
	@echo "Checking libft..."
	@make -C libft

project:
	@echo "Checking project..."

$(OBJSFD):
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $(OBJSFD) directory"

$(OBJSFD)%.o: $(SRCSFD)%.c $(HDRS) $(LIBFT)
	@gcc $(CFLAGS) $(HDR_INC) $(LIBFT_HDR) -c $< -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

clean:
	@/bin/rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"
	@make -C ./libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"
	@make -C ./libft fclean

re: fclean all

.PHONY: check_libft project clean fclean re
