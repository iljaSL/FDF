# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 16:52:45 by ismelich          #+#    #+#              #
#    Updated: 2020/01/30 17:00:37 by ismelich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = color.c controls_iso.c draw_hub.c main.c read_file.c 

OBJ = $(subst .c,.o,$(SRC))

FLAGS = -Wall -Wextra -Werror

CC = gcc

HEADER = fdf.h

MLX = -L/usr/local/lib -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

LIB_NAME = libft.a
LIB_PATH = ./libft/
LIB = $(LIB_PATH)$(LIB_NAME)

COLOR_RESET = \033[0m
COLOR_PENDING = \033[01;33m
COLOR_SUCCESS = \033[1;32m
COLOR_DEFAULT = \033[1;34m

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(LIB_NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	@make -C $(LIB_PATH)
	@echo "\033[A\033[K\033[A"
	@echo "$(LIB_NAME) [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "$(NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	@$(CC) $(FLAGS) $(OBJ) $(MLX) $(LIB) -o $(NAME)
	@echo "\033[A\033[K\033[A"
	@echo "$(NAME)     [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "        [$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)]"

run:
	./fdf test_maps/42.fdf

clean:
	@make -C $(LIB_PATH) clean
	@rm -f $(OBJ)
	@echo "$(NAME): $(COLOR_SUCCESS)$(OBJ) DELETED$(COLOR_RESET)"
	@echo "$(NAME): $(COLOR_SUCCESS)All object files were deleted$(COLOR_RESET)"

fclean: clean
	@make -C $(LIB_PATH) fclean
	@echo "$(NAME): $(COLOR_SUCCESS)$(LIB) DELETED$(COLOR_RESET)"
	@rm -rfv $(NAME)
	@echo "$(NAME): $(COLOR_SUCCESS)$(NAME) DELETED$(COLOR_RESET)"

re: fclean all

.PHONY: all clean debug fclean re run
