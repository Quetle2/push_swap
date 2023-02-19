/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:50:53 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/19 18:22:20 by miandrad         ###   ########.fr       */
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

void	check_best(t_list *node, t_list *first, t_moves *moves, int sizea)
{
	int				sizeb;
	static t_moves	local;
	t_list			*last;

	local.rota++;
	sizeb = get_size(first);
	last = ft_lstlast(first);
	moves_reset(&local);
	best_helper(node, first, last, &local);
	best_helperr(&local, sizea, sizeb);
	if (local.rota + local.rotb + local.rrot
		+ local.rrota + local.rrotb + local.rrrot
		< moves->rota + moves->rotb + moves->rrot
		+ moves->rrota + moves->rrotb + moves->rrrot)
	{
		moves->rota = local.rota;
		moves->rotb = local.rotb;
		moves->rrot = local.rrot;
		moves->rrotb = local.rrotb;
		moves->rrota = local.rrota;
		moves->rrrot = local.rrrot;
	}
	convert(node, &local, sizea);
}

void	first_node(t_list *node, t_list *first, t_moves *moves, int sizea)
{
	int		sizeb;
	t_moves	local;
	t_list	*last;

	sizeb = get_size(first);
	moves->rota = 0;
	local.rota = 0;
	last = ft_lstlast(first);
	moves_reset(&local);
	first_helper(node, first, last, &local);
	first_helperr(&local, sizea, sizeb);
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

	pb(a, b);
	pb(a, b);
	while (*a)
	{
		sort_helper(a, b, &moves);
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
