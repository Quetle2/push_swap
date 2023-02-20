/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:43:05 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/20 10:55:40 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct s_moves
{
	int	rota;
	int	rotb;
	int	rrot;
	int	rrota;
	int	rrotb;
	int	rrrot;
}t_moves;

typedef struct s_stack
{
	t_list			*head;
	int				size;
}t_stack;

void	printlist(t_list *node);

int		check_nbr(int argc, char **argv);
int		duplicate(t_list *list, int *nbr);
int		lesser_number(t_list *list);
int		take_input(t_stack *stack, int argc, char **argv);
int		check_order(t_list *lst);
int		reverse_order(t_list *lst);
void	moves_reset(t_moves *moves);
void	check_best(t_list *node, t_list *first, t_moves *moves, int sizea);
int		smaller(t_list *node, t_list *list);
int		bigger(t_list *node, t_list *list);
t_list	*biggest(t_list *list);
int		get_size(t_list *list);
void	first_node(t_list *node, t_list *first, t_moves *moves, int sizea);

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
void	rrr(t_list **a, t_list **b);

// SORT

void	trhee(t_list **list);
void	fives(t_list **a, t_list **b);
void	sort(t_list **a, t_list **b);


// HELPER

void	sort_helper(t_list **a, t_list **b, t_moves *moves);
void	first_helper(t_list *node, t_list *first, t_list *last, t_moves *local);
void	first_helperr(t_moves *local, int sizea, int sizeb);
void	best_helper(t_list *node, t_list *first, t_list *last, t_moves *local);
void	best_helperr(t_moves *local, int sizea, int sizeb);
void	convert(t_list *node, t_moves *local, int sizea);

#endif