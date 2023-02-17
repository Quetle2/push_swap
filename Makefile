# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 16:09:52 by miandrad          #+#    #+#              #
#    Updated: 2023/02/17 18:01:08 by miandrad         ###   ########.fr        #
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

ARG = 61 70 62 24 13 36 57 80 6 55 97 37 77 25 16 72 50 9 48 43 89 83 76 39 99 93 68 22 1 12 45 7 73 29 42 20 44 63 91 49 56 15 54 82 78 27 51 10 64 34 30 8 94 95 5 85 21 88 40 75 31 69 65 23 53 46 67 86 92 19 87 79 38 26 41 52 90 47 11 66 14 60 59 28 3 33 81 71 32 2 17 96 58 100 35 98 4 84 18 74 

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
	@echo "Committed and pushed" 

clean: 
	@$(RM) $(addprefix SRC/,$(OBJ))
	@make clean -s -C ft_printf

fclean: clean  
	@make fclean -s -C ft_printf
	@$(RM) $(NAME) $(LIB)

re: fclean all