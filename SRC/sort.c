/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:36:40 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/01 16:45:29 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	trhee(t_stack *stack)
{
	if (check_order(stack->head))
		return ;
	if (*(int *)stack->head->content > *(int *)stack->head->next->content)
	{
		ra(stack, 0);
		if (check_order(stack->head))
			return ;
		sa(stack, 0);
		if (check_order(stack->head))
			return ;
		ra(stack, 0);
	}
	if (check_order(stack->head))
		return ;
	if (*(int *)stack->head->content < *(int *)stack->head->next->content)
	{
		rra(stack, 0);
		if (check_order(stack->head))
			return ;
		sa(stack, 0);
	}
}

int	check_order(t_list *lst)
{
	while (lst->next)
	{
		if (*(int *)lst->content > *(int *)lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
