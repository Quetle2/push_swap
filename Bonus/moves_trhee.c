/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_trhee.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:38:00 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/20 12:46:14 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	if (b)
		rrb(b);
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
