/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:53:00 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/31 19:03:17 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack)
{
	t_list	*a;
	t_list	*b;

	a = pop(&stack->head);
	b = pop(&stack->head);
	ft_lstadd_front(&stack->head, a);
	ft_lstadd_front(&stack->head, b);
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	t_list	*a;
	t_list	*b;

	a = pop(&stack->head);
	b = pop(&stack->head);
	ft_lstadd_front(&stack->head, a);
	ft_lstadd_front(&stack->head, b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	if (b->head)
		sb(b);
}

t_list	*pop(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	return (temp);
}
