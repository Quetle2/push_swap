/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:21:40 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/17 16:04:00 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	smaller(t_list *node, t_list *list)
{
	while (list)
	{
		if (*node->content > *list->content)
			return (0);
		list = list->next;
	}
	return (1);
}

int	bigger(t_list *node, t_list *list)
{
	while (list)
	{
		if (*node->content < *list->content)
			return (0);
		list = list->next;
	}
	return (1);
}

t_list	*biggest(t_list *list)
{
	while (list->next)
	{
		if (bigger(list, list))
			return (list);
		list = list->next;
	}
	return (list);
}

t_list	*smallest(t_list *list)
{
	while (list->next)
	{
		if (smaller(list, list))
			return (list);
		list = list->next;
	}
	return (list);	
}

int	lesser_number(t_list *list)
{
	int	i;
	int	ye;
	int	nbr;

	i = 1;
	ye = 1;
	nbr = *list->content;
	while (list)
	{
		if (nbr > *list->content)
		{
			nbr = *list->content;
			ye = i;
		}
		i++;
		list = list->next;
	}
	return (ye);
}