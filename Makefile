# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrasin <skrasin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 11:03:57 by skrasin           #+#    #+#              #
#    Updated: 2020/03/11 11:28:01 by skrasin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLGS = -Wextra -Wall -Werror
FRAME = -lmlx -framework OpenGL -framework AppKit
SRC = *.c
LIB = Libft/libft.a
MLX = ./minilibx_macos/

all: $(NAME)

$(NAME):
	make -s -C Libft
	make -s -C minilibx_macos
	$(CC) $(CFLGS) $(SRC) $(LIB) $(FRAME) -L $(MLX) -o $(NAME)
clean:
	make -C Libft clean
	make -C minilibx_macos clean
fclean:
	rm -f $(NAME)
	make -s -C Libft fclean
	make -s -C minilibx_macos clean
re: fclean $(NAME)

.PHONY: all clean fclean re