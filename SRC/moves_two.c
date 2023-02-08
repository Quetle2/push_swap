/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:37:22 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/08 16:11:55 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **list, int flag)
{
	t_list	*node;

	node = pop(list);
	ft_lstadd_back(list, node);
	if (flag == 0)
		ft_printf("ra\n");
}

void	rb(t_list **list, int flag)
{
	t_list	*node;

	node = pop(list);
	ft_lstadd_back(list, node);
	if (flag == 0)
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 1);
	if (b)
		rb(b, 1);
}

void	rra(t_list **list, int flag)
{
	t_list	*node;

	node = *list;
	while (node->next->next)
		node = node->next;
	node = poplast(&node);
	ft_lstadd_front(list, node);
	if (flag == 0)
		ft_printf("rra\n");
}

void	rrb(t_list **list, int flag)
{
	t_list	*node;

	node = *list;
	while (node->next->next)
		node = node->next;
	node = poplast(&node);
	ft_lstadd_front(list, node);
	if (flag == 0)
		ft_printf("rrb\n");
}
