/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:55:36 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/27 13:54:44 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	replicate(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!replicate_two(a, b, line))
		{
			if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
				pa(a, b);
			else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
				pb(a, b);
			else
			{
				free(line);
				return (0);
			}
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (1);
}

int	replicate_two(t_list **a, t_list **b, char *line)
{
	if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(a, b);
	else if (line[0] == 'r' && line[1] == 'r'
		&& line[2] == 'a' && line[3] == '\n')
		rra(a);
	else if (line[0] == 'r' && line[1] == 'r'
		&& line[2] == 'b' && line[3] == '\n')
		rrb(b);
	else if (line[0] == 'r' && line[1] == 'r'
		&& line[2] == 'r' && line[3] == '\n')
		rrr(a, b);
	else if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(a, b);
	else
		return (0);
	return (1);
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
