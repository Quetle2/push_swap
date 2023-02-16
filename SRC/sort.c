/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:36:40 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/16 14:24:22 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	trhee(t_list **list)
{
	if (check_order(*list))
		return ;
	if (*(*list)->content > *(*list)->next->content)
	{
		ra(list, 0);
		if (check_order(*list))
			return ;
		sa(list, 0);
		if (check_order(*list))
			return ;
		ra(list, 0);
	}
	if (check_order(*list))
		return ;
	if (*(*list)->content < *(*list)->next->content)
	{
		rra(list, 0);
		if (check_order(*list))
			return ;
		sa(list, 0);
	}
}

void	fives(t_list **a, t_list **b)
{
	int	i;

	i = lesser_number(*a);
	if (i <= 3)
		while (--i != 0)
			ra(a, 0);
	else
		while (i-- - 4 != 0)
			rra(a, 0);
	pb(a, b);
	i = lesser_number(*a);
	if (i <= 3)
		while (--i != 0)
			ra(a, 0);
	else
		while (i-- - 3 != 0)
			rra(a, 0);
	pb(a, b);
	if (*(*b)->content < *(*b)->next->content)
		sb(b, 0);
	trhee(a);
	pa(a, b);
	pa(a, b);
}

int	check_order(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (*lst->content > *lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	printlist(t_list *node)
{
	if (node == NULL)
	{
		ft_printf("null\n");
		return ;
	}
	while (node != NULL)
	{
		ft_printf("--%d--\n", *node->content);
		node = node->next;
	}
	printf("end\n");
}
