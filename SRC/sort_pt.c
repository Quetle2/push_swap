/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:50:53 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/16 17:11:28 by miandrad         ###   ########.fr       */
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
	moves->rotb = 0;
	moves->rrot = 0;
	moves->rrota = 0;
	moves->rrotb = 0;
	moves->rrrot = 0;
}

void	check_best(t_list *node, t_list **list, t_moves *moves)
{
	static t_moves	local;
	t_list			*temp;

	temp = *list;
	local.rota++;
	moves_reset(&local);
	if (smaller(node, *list) || bigger(node, *list))
	{
		while (*temp->content != *biggest(*list)->content)
		{
			local.rotb++;
			temp = temp->next;
		}
	}
	else
	{
		while (temp->content > (*list)->content || temp->content < ft_lstlast(*list)->content)
		{
			local.rotb++;
			temp = temp->next;
		}
	}
	if (local.rota + local.rotb + local.rrota + local.rrotb < moves->rota + moves->rotb + moves->rrota + moves->rrotb)
	{
		moves->rota = local.rota;
		moves->rotb = local.rotb;
		moves->rrotb = local.rrotb;
		moves->rrota = local.rrota;
	}
}

void	first_node(t_list *node, t_list **list, t_moves *moves)
{
	t_moves	local;
	t_list			*temp;

	temp = *list;
	moves->rota = 0;
	moves_reset(&local);
	if (smaller(node, *list) || bigger(node, *list))
	{
		while (*temp->content != *biggest(*list)->content)
		{
			local.rotb++;
			temp = temp->next;
		}
	}
	else
	{
		while ((*list)->content > temp->content && ft_lstlast(*list)->content < temp->content)
		{
			local.rotb++;
			temp = temp->next;
		}
	}
	moves->rota = local.rota;
	moves->rotb = local.rotb;
	moves->rrotb = local.rrotb;
	moves->rrota = local.rrota;
}

void	sort(t_list **a, t_list **b)
{
	t_moves	moves;
	t_list	*node;

	pb(a, b);
	pb(a, b);
	while ((*a)->next->next->next)
	{
		node = *a;
		moves.rota = 0;
		moves_reset(&moves);
		first_node(node, b, &moves);
		while (node)
		{
			check_best(node, b, &moves);
			node = node->next;
		}
		while (moves.rota > 0 && moves.rotb > 0)
		{
			rr(a, b);
			moves.rota--;
			moves.rotb--;
		}	
		while (moves.rrota > 0 && moves.rrotb > 0)
		{
			rrr(a, b);
			moves.rrota--;
			moves.rrotb--;
		}
		ft_printf("moves.rota  %d \n", moves.rota);
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
		printlist(*b);
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
