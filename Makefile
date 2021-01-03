# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 22:31:44 by euyana-b          #+#    #+#              #
#    Updated: 2021/01/03 21:15:48 by euyana-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Cambiar el nombre........****
NAME	=	cub3D

SRC		=	src/cub3d.c src/init_structs.c src/keys.c\
			src/print_errors.c src/read_file.c src/screen.c\
			src/utils_read_file.c src/utils_screen.c\

GNL		=	gnl/get_next_line.c gnl/get_next_line_utils.c

LIBFT	=	libft/ft_atoi.c libft/ft_isdigit.c libft/ft_strncmp.c libft/ft_putstr_fd.c

OBJ	= 	$(SRC:.c=.o) $(GNL:.c=.o) $(LIBFT:.c=.o)

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
