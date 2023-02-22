/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_trhee.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:38:00 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/22 18:22:20 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_list **a, t_list **b)
{
	rra(a, 1);
	rrb(b, 1);
	ft_printf("rrr\n");
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
