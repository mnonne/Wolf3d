# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 13:17:40 by aminadzh          #+#    #+#              #
#    Updated: 2018/08/15 15:28:01 by aminadzh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = wolf3d

LIB_DIR = ./libft
SRC_DIR = ./src
INC_DIR = ./inc
BIN_DIR = bin
MLX_DIR = ./minilibx_macos

SRC     = draw_lines.c \
		  image.c \
		  init.c \
		  key_hooks.c \
		  key_llops.c \
		  key_loops_2.c \
		  main.c \
		  minimap.c \
		  obstacles.c \
		  read_map.c \
		  render_2.c \
		  render.c

OBJ     = $(addprefix $(BIN_DIR)/,$(SRC:.c=.o))

CC      = gcc
FLAGS   = -Wall -Werror -Wextra

MLX_I   = -I $(MLX_DIR)
MLX_L   = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: liball mlx_compile $(NAME)

$(OBJ): | $(BIN_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BIN_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -I $(INC_DIR) $(MLX_I) -o $@ -c $<

$(NAME): $(LIB) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -L$(LIB_DIR) -lft $(MLX_L) -o $(NAME)

$(LIB): liball mlx_compile

liball:
	make -C $(LIB_DIR) all

mlx_compile:
	make -C $(MLX_DIR) all

clean:
	make clean -C $(LIB_DIR)
	make clean -C $(MLX_DIR)
	rm -rf $(BIN_DIR)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all
