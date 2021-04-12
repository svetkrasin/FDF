# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svet <svet@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 11:03:57 by skrasin           #+#    #+#              #
#    Updated: 2021/04/11 22:15:57 by svet             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Sources
srcdir := ./srcs/
srcdirs := init
sources := $(foreach dir, $(addprefix $(srcdir), $(srcdirs)), $(wildcard $(dir)/*.c))

# Includes
LIBFT := ./Libft/
MLX := ./minilibx_macos/
incdir := ./includes
incdir += $(MLX) $(LIBFT)

#	Output
NAME := fdf

#	Compiler
CFLAGS := -g -Ofast -Wall -Wextra -Werror -pedantic
# -Weverything -Wno-poison-system-directories -Wno-cast-align -Wno-cast-qual
# -Wno-float-equal
CPPFLAGS := $(foreach dir, $(incdir), $(addprefix -I , $(dir)))

#CPPFLAGS := $(addprefix -I ,$(incdir))

#################
##  AUTO       ##
#################

SHELL := /bin/sh
objects := $(patsubst %.c, %.o, $(sources))
objects_bonus := $(patsubst %.c, %.o, $(wildcard $(addprefix $(srcdir), $(srcdirs_bonus))/*.c))
# .PRECIOUS: %.o

#################
##  TARGETS    ##
#################

#	First target
all: lib $(NAME)

#	Compiling libraries
lib:
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MLX)

#	Compiling the project
$(NAME) : $(objects)
	$(LINK.c) -o $(NAME) $(objects) $(LIBFT)libft.a $(MLX)libmlx.dylib
	install_name_tool -change libmlx.dylib @loader_path/$(MLX)/libmlx.dylib $(NAME)

#	Removing objects
clean:
#	@$(MAKE) -C $(LIBFT) clean
#	@$(MAKE) -C $(MLX) clean
	-$(RM) $(objects) $(objects_bonus)

#	Removing objects and the project
fclean: clean
	$(MAKE) -C $(MLX) clean
	$(MAKE) -C $(LIBFT) fclean
	-$(RM) $(NAME)

#	All removing than compiling
re: fclean all

.PHONY: all clean fclean re bonus srcs includes
