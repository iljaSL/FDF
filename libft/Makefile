# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 19:07:50 by ismelich          #+#    #+#              #
#    Updated: 2020/01/22 18:09:27 by ismelich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strdup.c \
	  ft_strncpy.c \
	  ft_strncat.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strnew.c \
	  ft_strsub.c \
	  ft_strcpy.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_strndup.c \
	  ft_itoa.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isdigit.c \
	  ft_isspace.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_isprint.c \
	  ft_isalpha.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_memcmp.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putnbr_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strclr.c \
	  ft_strdel.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_isblank.c \
	  ft_islower.c \
	  ft_isupper.c \
	  ft_words_counter.c \
	  get_next_line.c \
	  ft_abs.c 

OBJ = $(subst .c,.o,$(SRC))

INCLUDES=includes/libft.h includes/get_next_line.h

all: $(NAME) 

$(NAME): $(SRC) includes/libft.h
	@gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@rm includes/get_next_line.h.gch

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
