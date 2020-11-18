# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euyana-b ∫ <euyana-b@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/14 14:12:39 by klever            #+#    #+#              #
#    Updated: 2020/11/18 18:38:57 by euyana-b ∫       ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#Cambiar el nombre........****
NAME	= 	cub3D

SRC		= 	src/cub3d.c src/utils.c

GNL		=	gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ	= 	$(SRC:.c=.o) $(GNL:.c=.o)

CC		= gcc

CFLAGS = -O3 -Wall -Wextra -Werror

MLX = minilibx

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = src/cub3d.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) -L $(MLX) $(LXFLAGS) $(OBJ)

clean:
	rm -rf $(OBJ)
	rm -f bitmap.bmp
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
