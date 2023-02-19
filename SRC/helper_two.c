/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:24:22 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/19 18:31:52 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	convert(t_list *node, t_moves *local, int sizea)
{
	if (local->rrrot != 0)
		local->rrota = local->rrota + local->rrrot;
	if (local->rrota != 0)
		local->rota = sizea - local->rrota;
	if (local->rrot != 0)
		local->rota = local->rota + local->rrot;
	if (node->next == NULL)
		local->rota = 0;
}
