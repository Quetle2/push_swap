/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_trhee.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:38:00 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/01 14:48:15 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 1);
	if (b->head)
		rrb(b, 1);
}

t_list	*pop(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	return (temp);
}

t_list	*poplast(t_list **lst)
{
	t_list	*temp;

	temp = (*lst)->next;
	(*lst)->next = NULL;
	return (temp);
}
