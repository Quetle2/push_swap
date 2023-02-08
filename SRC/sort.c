/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:36:40 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/08 13:27:17 by miandrad         ###   ########.fr       */
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

// testing

void	mergesort(t_list **headRef)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *headRef;
/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL))
	{
		return ;
	}
/* Split head into 'a' and 'b' sublists */
	frontbacksplit(head, &a, &b);
/* Recursively sort the sublists */
	mergesort(&a);
	mergesort(&b);
/* answer = merge the two sorted lists together */
	*headRef = sortedmerge(a, b);
}

t_list	*sortedmerge(t_list *a, t_list *b)
{
	t_list	*result;

	result = NULL;
/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
/* Pick either a or b, and recur */
	if (*a->content <= *b->content)
	{
		result = a;
		result->next = sortedmerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sortedmerge(a, b->next);
	}
	return (result);
}

void	frontbacksplit(t_list *source, t_list **frontRef, t_list **backRef)
{
	t_list	*fast;
	t_list	*slow;

	slow = source;
	fast = source->next;
/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
//'slow' is before the midpoint in the list, so split it in two at that point.
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

void	printList(t_list *node)
{
	while (node != NULL)
	{
		printf("--%d-- \n", *node->content);
		node = node->next;
	}
}
