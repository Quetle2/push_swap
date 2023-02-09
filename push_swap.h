/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:43:05 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/08 16:29:21 by miandrad         ###   ########.fr       */
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

void	printList(t_list *node);

int		check_nbr(int argc, char **argv);
void	take_input(t_stack *stack, int argc, char **argv);
void	trhee(t_stack *stack);
int		check_order(t_list *lst);

// MOVES

t_list	*pop(t_list **lst);
t_list	*poplast(t_list **lst);
void	sa(t_list **list, int flag);
void	sb(t_list **list, int flag);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **list, int flag);
void	rb(t_list **list, int flag);
void	rr(t_list **a, t_list **b);
void	rra(t_list **list, int flag);
void	rrb(t_list **list, int flag);
void	rrr(t_list *a, t_list *b);

// SORT

void	mergesort(t_list **headRef);
void	sort(t_list **a, t_list **b);
t_list	*sortedmerge(t_list *a, t_list *b);
void	frontbacksplit(t_list *source, t_list **frontRef, t_list **backRef);

#endif