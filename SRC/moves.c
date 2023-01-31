/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:53:00 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/31 13:40:51 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack)
{
	t_list	*a;
	t_list	*b;

	a = pop(&stack->head);
	b = pop(&stack->head);
	ft_printf("sa\n");
}

t_list	*pop(t_list **lst)
{
	
}
