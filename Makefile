# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lderks <lderks@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2026/03/10 16:21:44 by doda-cun      #+#    #+#                  #
#    Updated: 2026/04/06 18:07:13 by lderks        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME    = miniRT

MLX_DIR = ./mlx
MLX     = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT_DIR			= ./libft
LIBFT				= $(LIBFT_DIR)/libft.a

INC		= include/
SRC_DIR = src/
OBJ_DIR = obj/

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I$(INC) -I$(MLX_DIR) -I$(LIBFT_DIR)

SRCS = main.c $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

