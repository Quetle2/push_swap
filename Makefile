# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 16:09:52 by miandrad          #+#    #+#              #
#    Updated: 2023/02/09 09:07:14 by miandrad         ###   ########.fr        #
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

ARG = 5 4 3 2 1

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

git: 
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