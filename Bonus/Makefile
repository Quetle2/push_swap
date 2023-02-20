# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 11:03:38 by miandrad          #+#    #+#              #
#    Updated: 2023/02/20 12:44:17 by miandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

LIB = checker.a

SRC = main.c moves.c moves_two.c moves_trhee.c replicate.c get_next_line_100/get_next_line.c get_next_line_100/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) checker.h
	@make -s -C ../ft_printf
	@ar rcs $(LIB) $(OBJ)
	@$(CC) $(LIB) ../ft_printf/libftprintf.a -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) $(LIB)

re: fclean all