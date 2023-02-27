/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:29:08 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/24 17:21:40 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_helper(t_list **a, t_list **b, t_moves *moves)
{
	t_list	*node;

	node = *a;
	moves->rota = 0;
	moves_reset(moves);
	first_node(node, *b, moves, get_size(*a));
	node = node->next;
	while (node)
	{
		check_best(node, *b, moves, get_size(*a));
		node = node->next;
	}
	while (moves->rrot-- > 0)
		rr(a, b);
	while (moves->rrrot-- > 0)
		rrr(a, b);
	while (moves->rota-- > 0)
		ra(a, 0);
	while (moves->rotb-- > 0)
		rb(b, 0);
	while (moves->rrota-- > 0)
		rra(a, 0);
	while (moves->rrotb-- > 0)
		rrb(b, 0);
	pb(a, b);
}

void	first_helper(t_list *node, t_list *first, t_list *last, t_moves *local)
{
	if (smaller(node, first) || bigger(node, first))
	{
		while (*first->content != *biggest(first)->content)
		{
			local->rotb++;
			first = first->next;
		}
	}
	else
	{
		while (first && (*node->content < *first->content
				|| *node->content > *last->content))
		{
			local->rotb++;
			if (last->next == NULL)
				last = first;
			else
				last = last->next;
			first = first->next;
		}
	}
}

void	first_helperr(t_moves *local, int sizea, int sizeb)
{
	if (local->rota > sizea / 2)
	{
		local->rrota = sizea - local->rota;
		local->rota = 0;
	}
	if (local->rotb > sizeb / 2)
	{
		local->rrotb = sizeb - local->rotb;
		local->rotb = 0;
	}
	while (local->rota > 0 && local->rotb > 0)
	{
		local->rota--;
		local->rotb--;
		local->rrot++;
	}
	while ((local->rrota > 0 && local->rrotb > 0))
	{
		local->rrota--;
		local->rrotb--;
		local->rrrot++;
	}
}

void	best_helper(t_list *node, t_list *first, t_list *last, t_moves *local)
{
	if (smaller(node, first) || bigger(node, first))
	{
		while (*first->content != *biggest(first)->content)
		{
			local->rotb++;
			first = first->next;
		}
	}
	else
	{
		while (first && (*node->content < *first->content
				|| *node->content > *last->content))
		{
			local->rotb++;
			if (last->next == NULL)
				last = first;
			else
				last = last->next;
			first = first->next;
		}
	}
}

void	best_helperr(t_moves *local, int sizea, int sizeb)
{
	if (local->rota > sizea / 2)
	{
		local->rrota = sizea - local->rota;
		local->rota = 0;
	}
	if (local->rotb > sizeb / 2)
	{
		local->rrotb = sizeb - local->rotb;
		local->rotb = 0;
	}
	while (local->rota > 0 && local->rotb > 0)
	{
		local->rota--;
		local->rotb--;
		local->rrot++;
	}
	while ((local->rrota > 0 && local->rrotb > 0))
	{
		local->rrota--;
		local->rrotb--;
		local->rrrot++;
	}
}
