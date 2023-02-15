/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:50:53 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/15 16:52:33 by miandrad         ###   ########.fr       */
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
			node = node->next;
			moves.rota++;
		}
		while (moves.rota-- && moves.rotb--)
			rr(a, b);
		while (moves.rrota-- && moves.rrotb--)
			rrr(a, b);
		while (moves.rota--)
			ra(a, 0);
		while (moves.rotb--)
			rb(b, 0);
		while (moves.rrota--)
			rra(a, 0);
		while (moves.rrotb--)
			rrb(b, 0);
	}
	trhee(a);
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
