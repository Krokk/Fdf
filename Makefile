# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 10:20:20 by rfabre            #+#    #+#              #
#    Updated: 2017/10/31 13:59:47 by tchapka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC =	fdf.c ft_parsing.c ft_checkmap.c ft_newmap.c ft_painter.c \
			ft_eventmap.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ./libft/libft.a
MLX = minilibx_macos/
FRAMEWORKS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
		@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m :\tLibrary compilation in progress..."
		@make -C libft/
		@make -C $(MLX)
		@$(CC) $(CFLAGS) $(LIB) $(OBJ) -I $(MLX) -L $(MLX) -lmlx $(FRAMEWORKS) -o $(NAME)
		@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m :\tLibrary compilation completed successfully !"

clean:
	@echo "\t\033[1;31m'CLEAN' ->\tDestruction\033[0m:\tfiles .o for \033[1;34m$(NAME)\033[0m"
	@make -C $(MLX) clean
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)
	@echo "\t\033[1;31m'CLEAN' ->\tDestruction\033[0m:\tfiles .o for \033[1;34m$(NAME)\033[0m completed successfully !"

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@echo "\t\033[1;31m'FCLEAN' ->\tDestruction\033[0m: of \033[1;34m$(NAME)\033[0m completed successfully !"

re: fclean all

.PHONY: all clean fclean re
