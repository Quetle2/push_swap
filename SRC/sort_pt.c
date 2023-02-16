/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:50:53 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/16 12:25:22 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	sort(t_list **a, t_list **b)
// {
// 	int	flag;

// 	while (*a)
// 	{
// 		flag = 0;
// 		if (*b && *(*b)->content > *(*a)->content)
// 			ra(a, 0);
// 		while (*b && *(*b)->content > *ft_lstlast(*a)->content)
// 		{
// 			pa(a, b);
// 			flag = 1;
// 		}
// 		if (flag == 1)
// 			rra(a, 0);
// 		pb(a, b);
// 		if ((*b)->next != NULL && reverse_order(*b) && check_order(*a))
// 		{
// 			break ;
// 		}
// 	}
// 	while (*b)
// 		pa(a, b);
// }

void	moves_reset(t_moves *moves)
{
	moves->rota = 0;
	moves->rotb = 0;
	moves->rrot = 0;
	moves->rrota = 0;
	moves->rrotb = 0;
	moves->rrrot = 0;
}

void	check_best(t_list **a, t_list **b, t_moves *moves)
{
	t_moves	local;

	moves_reset(&local);
	local.rota = moves->rota;
	while ()
	{

	}
}

void	sort(t_list **a, t_list **b)
{
	t_moves	moves;
	t_list	*node;

	node = *a;
	pb(a, b);
	pb(a, b);
	while ((*a)->next->next->next)
	{
		moves_reset(&moves);
		while (node)
		{
			check_best(a, b, &moves);
			node = node->next;
			moves.rota++;
		}
		while (moves.rota-- > 0 && moves.rotb-- > 0)
			rr(a, b);
		while (moves.rrota-- > 0 && moves.rrotb-- > 0)
			rrr(a, b);
		while (moves.rota-- > 0)
			ra(a, 0);
		while (moves.rotb-- > 0)
		{
			rb(b, 0);
			ft_printf("%i\n", moves.rotb);
		}
		while (moves.rrota-- > 0)
			rra(a, 0);
		while (moves.rrotb-- > 0)
			rrb(b, 0);
		pb(a, b);
	}
	trhee(a);
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
