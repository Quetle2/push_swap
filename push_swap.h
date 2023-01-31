/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:43:05 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/31 18:05:04 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	t_list			*head;
	int				size;
}t_stack;

int		check_nbr(int argc, char **argv);
void	take_input(t_stack *stack, int argc, char **argv);

// MOVES

t_list	*pop(t_list **lst);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);

#endif