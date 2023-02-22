# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 16:09:52 by miandrad          #+#    #+#              #
#    Updated: 2023/02/22 19:48:08 by miandrad         ###   ########.fr        #
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

BONUS = checker

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

LIB = push_swap.a

B_LIB = checker.a

SRC = main.c moves.c moves_two.c moves_trhee.c sort.c sort_pt.c checker.c helper.c helper_two.c

B_SRC = main.c moves.c moves_two.c moves_trhee.c replicate.c get_next_line_100/get_next_line.c get_next_line_100/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

ARG = 1213 98 61 42 94 45 9 8 2

all: $(NAME)

bonus:	$(BONUS)

$(NAME): $(addprefix SRC/,$(OBJ)) push_swap.h
	@make -s -C ft_printf
	@ar rcs $(LIB) $(addprefix SRC/,$(OBJ))
	@$(CC) $(LIB) ft_printf/libftprintf.a -o $(NAME)

$(BONUS): $(addprefix Bonus/,$(B_OBJ))
	@make -s -C ft_printf
	@ar rcs $(addprefix Bonus/,$(B_LIB)) $(addprefix Bonus/,$(B_OBJ))
	@$(CC) $(addprefix Bonus/,$(B_LIB)) ft_printf/libftprintf.a -o $(BONUS)

run: $(NAME)
	@./push_swap $(ARG)

check: $(NAME)
	@./push_swap $(ARG) | ./checker $(ARG)

valgrind: $(NAME)
	@valgrind --leak-check=full ./push_swap $(ARG)

git: fclean
	@git add .
	@git commit
	@git push
	@echo " -------Commited and Pushed------- "

clean: 
	@$(RM) $(addprefix SRC/,$(OBJ))
	@$(RM) $(addprefix Bonus/,$(B_OBJ))
	@make clean -s -C ft_printf

fclean: clean  
	@make fclean -s -C ft_printf
	@$(RM) $(NAME) $(LIB) $(BONUS) Bonus/$(B_LIB)

re: fclean all