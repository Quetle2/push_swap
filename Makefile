# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 16:09:52 by miandrad          #+#    #+#              #
#    Updated: 2023/02/17 18:00:59 by miandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	3 numbers -> 2 or 3 moves
#	5 numbers -> <=12 moves
#	100 numbers:
#		<=700 moves = 5pts
#		<=900 numbers = 4pts
#		<=1,100 numbers = 3pts
#		<=1,300 numbers = 2pts
#		<=1,500 numbers = 1pts
#	500 numbers:
#		<=5,500 moves = 5pts
#		<=7,000 moves = 4pts
#		<=8,500 moves = 3pts
#		<=10,000 moves = 2pts
#		<=11,500 moves = 1pts

NAME = push_swap

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

LIB = push_swap.a

SRC = main.c moves.c moves_two.c moves_trhee.c sort.c sort_pt.c checker.c

OBJ = $(SRC:.c=.o)

ARG = 57 66 84 56 1 52 49 74 19 99 68 98 43 86 48 11 15 25 41 33 87 78 40 29 31 65 69 96 73 100 55 45 3 60 14 17 42 28 35 24 92 26 6 91 30 38 90 18 47 88 89 10 21 36 32 80 34 44 77 61 4 54 9 23 51 2 79 63 75 81 85 83 50 76 70 13 5 72 67 59 37 58 97 71 12 62 22 27 16 94 7 46 53 20 64 93 82 95 8 39

all: $(NAME)

$(NAME): $(addprefix SRC/,$(OBJ)) push_swap.h
	@make -s -C ft_printf
	@ar rcs $(LIB) $(addprefix SRC/,$(OBJ))
	@$(CC) $(LIB) ft_printf/libftprintf.a -o $(NAME)

run: $(NAME)
	@./push_swap $(ARG)

check: $(NAME)
	@./push_swap $(ARG) | ./checker_linux $(ARG)

valgrind: $(NAME)
	@valgrind --leak-check=full ./push_swap $(ARG)

git: clean
	@git add .
	@git commit
	@git push
	@echo "Commited and Pushed"

clean: 
	@$(RM) $(addprefix SRC/,$(OBJ))
	@make clean -s -C ft_printf

fclean: clean  
	@make fclean -s -C ft_printf
	@$(RM) $(NAME) $(LIB)

re: fclean all