# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchudik <mchudik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/07 17:57:28 by mchudik           #+#    #+#              #
#    Updated: 2019/07/19 12:25:18 by mchudik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
SRC = src/main.c \
		src/read_file.c \
		src/read.c \
		src/draw.c \
		src/keys.c\
		src/mouse.c \
		src/check_map.c \
		src/draw1.c \
		src/draw2.c \
		src/textures.c \
		src/mini_map.c \
		src/move.c \
		src/music.c \
		src/draw3.c \
		src/menu.c

OUT = $(SRC:.c=.o)

INC = ./inc/wolf3d.h

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OUT)
	make -C ./libft
	gcc $(FLAGC) -o $(NAME) $(OUT) $(MLX) ./libft/libft.a -I$(INC)
	@echo 'Compilated!'

clean:
	rm -f $(OUT)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
