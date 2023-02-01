/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:53:00 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/01 13:47:26 by miandrad         ###   ########.fr       */
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

void	ra(t_stack *stack)
{
	t_list	*node;

	node = pop(&stack->head);
	ft_lstadd_back(&stack->head, node);
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	t_list	*node;

	node = pop(&stack->head);
	ft_lstadd_back(&stack->head, node);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	if (b->head)
		rb(b);
}

void	rra(t_stack *stack)
{
	t_list	*node;

	node = stack->head;
	while (node->next->next)
		node = node->next;
	node = poplast(&node);
	ft_lstadd_front(&stack->head, node);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	t_list	*node;

	node = stack->head;
	while (node->next->next)
		node = node->next;
	node = poplast(&node);
	ft_lstadd_front(&stack->head, node);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	if (b->head)
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
