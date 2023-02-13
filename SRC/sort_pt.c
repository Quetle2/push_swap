/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:50:53 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/13 16:43:27 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_list **a, t_list **b)
{
	int	flag;

	while (*a)
	{
		flag = 0;
		if (*b && *(*b)->content > *(*a)->content)
			ra(a, 0);
		while (*b && *(*b)->content > *ft_lstlast(*a)->content)
		{
			pa(a, b);
			flag = 1;
		}
		if (flag == 1)
			rra(a, 0);
		pb(a, b);
		// printlist(*a);
		// printlist(*b);
		if ((*b)->next != NULL && reverse_order(*b) && check_order(*a))
		{
			break ;
		}
	}
	while (*b)
		pa(a, b);
}

int	reverse_order(t_list *lst)
{
	// ft_printf("\naqui\n");
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (*lst->content < *lst->next->content)
			return (0);
		lst = lst->next;
	}
	return(1);
}
