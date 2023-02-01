/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:53:00 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/01 14:41:30 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack, int flag)
{
	t_list	*a;
	t_list	*b;

	a = pop(&stack->head);
	b = pop(&stack->head);
	ft_lstadd_front(&stack->head, a);
	ft_lstadd_front(&stack->head, b);
	if (flag == 0)
		ft_printf("sa\n");
}

void	sb(t_stack *stack, int flag)
{
	t_list	*a;
	t_list	*b;

	a = pop(&stack->head);
	b = pop(&stack->head);
	ft_lstadd_front(&stack->head, a);
	ft_lstadd_front(&stack->head, b);
	if (flag == 0)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 1);
	if (b->head)
		sb(b, 1);
	ft_printf("s\n");
}

void	pa(t_stack *a, t_stack *b)
{
	t_list	*node;

	node = pop(&b->head);
	ft_lstadd_front(&a->head, node);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_list	*node;

	node = pop(&a->head);
	ft_lstadd_front(&b->head, node);
	ft_printf("pb\n");
}
