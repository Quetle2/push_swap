/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:50:53 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/18 10:01:21 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	moves_reset(t_moves *moves)
{
	moves->rotb = 0;
	moves->rrot = 0;
	moves->rrota = 0;
	moves->rrotb = 0;
	moves->rrrot = 0;
}

void	check_best(t_list *node, t_list *first, t_moves *moves, int sizeb, int sizea)
{
	static t_moves	local;
	t_list	*last;

	local.rota++;
	last = ft_lstlast(first);
	moves_reset(&local);
	if (smaller(node, first) || bigger(node, first))
	{
		while (*first->content != *biggest(first)->content)
		{
			local.rotb++;
			first = first->next;
		}
	}
	else
	{
		while (first && (*node->content < *first->content || *node->content > *last->content))
		{
			local.rotb++;
			if (last->next == NULL)
				last = first;
			else
				last = last->next;
			first = first->next;
		}
	}
	// ft_printf("locals  %i  %i  %i  %i\n", local.rota, local.rotb, local.rrota, local.rrotb);
	// ft_printf("moves   %i  %i  %i  %i\n", moves->rota, moves->rotb, moves->rrota, moves->rrotb);
	if (local.rota > sizea / 2)
	{
		local.rrota = sizea - local.rota;
		local.rota = 0;
	}
	if (local.rotb > sizeb / 2)
	{
		local.rrotb = sizeb - local.rotb;
		local.rotb = 0;
	}
	while (local.rota > 0 && local.rotb > 0)
	{
		local.rota--;
		local.rotb--;
		local.rrot++;
	}
	while (local.rrota > 0 && local.rrotb > 0)
	{
		local.rrota--;
		local.rrotb--;
		local.rrrot++;
	}
	// ft_printf("locals  %i  %i  %i  %i\n", local.rota, local.rotb, local.rrota, local.rrotb);
	// ft_printf("moves   %i  %i  %i  %i\n", moves->rota, moves->rotb, moves->rrota, moves->rrotb);
	if (local.rota + local.rotb + local.rrot + local.rrota + local.rrotb + local.rrrot < moves->rota + moves->rotb + moves->rrot + moves->rrota + moves->rrotb + moves->rrrot)
	{
		moves->rota = local.rota;
		moves->rotb = local.rotb;
		moves->rrot = local.rrot;
		moves->rrotb = local.rrotb;
		moves->rrota = local.rrota;
		moves->rrrot = local.rrrot;
	}
	if (local.rrrot != 0)
		local.rrota = local.rrota + local.rrrot;
	if (local.rrota != 0)
		local.rota = sizea - local.rrota;
	if (local.rrot != 0)
		local.rota = local.rota + local.rrot;
	if (node->next == NULL)
		local.rota = 0;
}

void	first_node(t_list *node, t_list *first, t_moves *moves, int sizeb, int sizea)
{
	t_moves	local;
	t_list	*last;

	moves->rota = 0;
	local.rota = 0;
	last = ft_lstlast(first);
	moves_reset(&local);
	if (smaller(node, first) || bigger(node, first))
	{
		while (*first->content != *biggest(first)->content)
		{
			local.rotb++;
			first = first->next;
		}
	}
	else
	{
		while (first && (*node->content < *first->content || *node->content > *last->content))
		{
			local.rotb++;
			if (last->next == NULL)
				last = first;
			else
				last = last->next;
			first = first->next;
		}
	}
	if (local.rota > sizea / 2)
	{
		local.rrota = sizea - local.rota;
		local.rota = 0;
	}
	if (local.rotb > sizeb / 2)
	{
		local.rrotb = sizeb - local.rotb;
		local.rotb = 0;
	}
	while (local.rota > 0 && local.rotb > 0)
	{
		local.rota--;
		local.rotb--;
		local.rrot++;
	}
	while ((local.rrota > 0 && local.rrotb > 0))
	{
		local.rrota--;
		local.rrotb--;
		local.rrrot++;
	}
	moves->rota = local.rota;
	moves->rotb = local.rotb;
	moves->rrot = local.rrot;
	moves->rrotb = local.rrotb;
	moves->rrota = local.rrota;
	moves->rrrot = local.rrrot;
}

void	sort(t_list **a, t_list **b)
{
	t_moves	moves;
	t_list	*node;

	pb(a, b);
	pb(a, b);
	while (*a)
	{
		node = *a;
		moves.rota = 0;
		moves_reset(&moves);
		first_node(node, *b, &moves, get_size(*b), get_size(*a));
		node = node->next;
		while (node)
		{
			check_best(node, *b, &moves, get_size(*b), get_size(*a));
			node = node->next;
		}
		while (moves.rrot > 0)
		{
			rr(a, b);
			moves.rrot--;
		}
		while (moves.rrrot > 0)
		{
			rrr(a, b);
			moves.rrrot--;
		}
		while (moves.rota > 0)
		{
			ra(a, 0);
			moves.rota--;
		}
		while (moves.rotb > 0)
		{
			rb(b, 0);
			moves.rotb--;
		}
		while (moves.rrota > 0)
		{
			rra(a, 0);
			moves.rrota--;
		}
		while (moves.rrotb > 0)
		{
			rrb(b, 0);
			moves.rrotb--;
		}
		pb(a, b);
		// printlist(*b);
	}
	if (get_size(*b) - get_size(biggest(*b)) <= get_size(*b) / 2)
		while (*(*b)->content != *biggest(*b)->content)
			rb(b, 0);
	else
		while (*(*b)->content != *biggest(*b)->content)
			rrb(b, 0);
	while (*b)
		pa(a, b);
}

int	reverse_order(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (*lst->content < *lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
