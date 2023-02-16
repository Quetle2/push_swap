# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 16:09:52 by miandrad          #+#    #+#              #
#    Updated: 2023/02/09 11:21:34 by miandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	3 numbers -> 2 or 3 moves
#	5 numbers -> <12 moves
#	100 numbers:
#		<700 moves = 5pts
#		<900 numbers = 4pts
#		<1,100 numbers = 3pts
#		<1,300 numbers = 2pts
#		<1,500 numbers = 1pts
#	500 numbers:
#		<5,500 moves = 5pts
#		<7,000 moves = 4pts
#		<8,500 moves = 3pts
#		<10,000 moves = 2pts
#		<11,500 moves = 1pts

NAME = push_swap

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

LIB = push_swap.a

SRC = main.c moves.c moves_two.c moves_trhee.c sort.c sort_pt.c

OBJ = $(SRC:.c=.o)

ARG = 79 86 25 89 37 8 54 18 58 56 6 4 36 42 1 38 48 57 76 61 11 49 19 94 28 78 68 52 99 13 72 96 63 83 91 75 23 15 62 77 46 40 20 14 90 43 92 69 10 74 16 66 98 55 95 84 34 88 39 12 70 21 41 51 87 9 26 100 45 80 60 32 97 27 30 81 67 17 24 85 64 7 47 2 65 29 22 82 3 73 93 59 71 33 50 5 35 53 31 44

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
	git add .
	git commit
	git push

clean: 
	@$(RM) $(addprefix SRC/,$(OBJ))
	@make clean -s -C ft_printf

fclean: clean  
	@make fclean -s -C ft_printf
	@$(RM) $(NAME) $(LIB)

re: fclean all