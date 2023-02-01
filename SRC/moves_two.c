/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:37:22 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/01 15:41:26 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack, int flag)
{
	t_list	*node;

	node = pop(&stack->head);
	ft_lstadd_back(&stack->head, node);
	if (flag == 0)
		ft_printf("ra\n");
}

void	rb(t_stack *stack, int flag)
{
	t_list	*node;

	node = pop(&stack->head);
	ft_lstadd_back(&stack->head, node);
	if (flag == 0)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 1);
	if (b->head)
		rb(b, 1);
}

void	rra(t_stack *stack, int flag)
{
	t_list	*node;

	node = stack->head;
	while (node->next->next)
		node = node->next;
	node = poplast(&node);
	ft_lstadd_front(&stack->head, node);
	if (flag == 0)
		ft_printf("rra\n");
}

void	rrb(t_stack *stack, int flag)
{
	t_list	*node;

	node = stack->head;
	while (node->next->next)
		node = node->next;
	node = poplast(&node);
	ft_lstadd_front(&stack->head, node);
	if (flag == 0)
		ft_printf("rrb\n");
}
