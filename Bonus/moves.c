/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:53:00 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/20 12:45:51 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list **list)
{
	t_list	*a;
	t_list	*b;

	a = pop(list);
	b = pop(list);
	ft_lstadd_front(list, a);
	ft_lstadd_front(list, b);
}

void	sb(t_list **list)
{
	t_list	*a;
	t_list	*b;

	a = pop(list);
	b = pop(list);
	ft_lstadd_front(list, a);
	ft_lstadd_front(list, b);
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	if (b)
		sb(b);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*node;

	node = pop(b);
	ft_lstadd_front(a, node);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*node;

	node = pop(a);
	ft_lstadd_front(b, node);
}
