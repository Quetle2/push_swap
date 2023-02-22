/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:55:36 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/22 12:05:26 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// int	replicate(t_list **a, t_list **b)
// {
// 	char	*line;

// 	line = get_next_line(2);
// 	while (line)
// 	{
// 		if (line[1] == 'a' && line[2] == '\n')
// 		{
// 			if (line[0] == 'r')
// 				ra(a, 0);
// 			else if (line[0] == 's')
// 				sa(a, 0);
// 			else if (line[0] == 'p')
// 				pa(a, 0);
// 			else
// 				return (0);
// 		}
// 		else if (line[1] == 'b')
// 		{
// 			if (line[0] == 'r')
// 				rb(a, 0);
// 			else if (line[0] == 's')
// 				sb(a, 0);
// 			else if (line[0] == 'p')
// 				pb(a, 0);
// 			else
// 				return (0);
// 		}
// 		else if (line[2] == 'a')
// 			rra(a, 0);
// 		else if (line[2] == 'b')
// 			rrb(b, 0);
// 		else if (line[2] == 'r')
// 			rrr(a, b);
// 		else if (line[1] == 'r' && line[2] == '\n')
// 			rr(a, b);
// 		else if (line[1] == 's')
// 			ss(a, b);
// 		else
// 			return (0);
// 		free(line);
// 		line = get_next_line(2);
// 	}
// 	free(line);
// 	return (1);
// }

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
			free(line);
		}
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
		rrb(a);
	else if (line[0] == 'r' && line[1] == 'r'
		&& line[2] == 'r' && line[3] == '\n')
		rrr(a, b);
	else if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(a);
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
