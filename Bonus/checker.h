/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:05:25 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/20 13:16:51 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../ft_printf/ft_printf.h"
# include "get_next_line_100/get_next_line.h"

typedef struct s_stack
{
	t_list			*head;
	int				size;
}t_stack;

t_list	*pop(t_list **lst);
t_list	*poplast(t_list **lst);
void	sa(t_list **list);
void	sb(t_list **list);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **list);
void	rb(t_list **list);
void	rr(t_list **a, t_list **b);
void	rra(t_list **list);
void	rrb(t_list **list);
void	rrr(t_list **a, t_list **b);

int		replicate(t_list **a, t_list **b);
int		replicate_two(t_list **a, t_list **b, char *line);
int		take_input(t_stack *stack, int argc, char **argv);
void	stack_init(t_stack *stack, int argc);
int		check_nbr(int argc, char **argv);
int		duplicate(t_list *list, int *nbr);
int		check_order(t_list *lst);

#endif