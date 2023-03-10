/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:37:22 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/22 18:24:57 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_list **list)
{
	t_list	*node;

	if (!*list || !(*list)->next)
		return ;
	node = pop(list);
	ft_lstadd_back(list, node);
}

void	rb(t_list **list)
{
	t_list	*node;

	if (!*list || !(*list)->next)
		return ;
	node = pop(list);
	ft_lstadd_back(list, node);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}

void	rra(t_list **list)
{
	t_list	*node;

	if (!*list || !(*list)->next)
		return ;
	node = *list;
	while (node->next->next)
		node = node->next;
	node = poplast(&node);
	ft_lstadd_front(list, node);
}

void	rrb(t_list **list)
{
	t_list	*node;

	if (!*list || !(*list)->next)
		return ;
	node = *list;
	while (node->next->next)
		node = node->next;
	node = poplast(&node);
	ft_lstadd_front(list, node);
}
