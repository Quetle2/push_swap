/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:53:00 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/22 18:10:35 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **list, int flag)
{
	t_list	*a;
	t_list	*b;

	if (!*list || !(*list)->next)
		return ;
	a = pop(list);
	b = pop(list);
	ft_lstadd_front(list, a);
	ft_lstadd_front(list, b);
	if (flag == 0)
		ft_printf("sa\n");
}

void	sb(t_list **list, int flag)
{
	t_list	*a;
	t_list	*b;

	if (!*list || !(*list)->next)
		return ;
	a = pop(list);
	b = pop(list);
	ft_lstadd_front(list, a);
	ft_lstadd_front(list, b);
	if (flag == 0)
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a, 1);
	sb(b, 1);
	ft_printf("ss\n");
}

void	pa(t_list **a, t_list **b)
{
	t_list	*node;

	if (!*b)
		return ;
	node = pop(b);
	ft_lstadd_front(a, node);
	ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*node;

	if (!*a)
		return ;
	node = pop(a);
	ft_lstadd_front(b, node);
	ft_printf("pb\n");
}
