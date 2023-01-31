/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:29:57 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/31 19:07:53 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int *content)
{
	struct s_list	*cabeca;

	cabeca = malloc(sizeof(struct s_list));
	if (!cabeca)
		return (0);
	cabeca->content = content;
	cabeca->next = NULL;
	return (cabeca);
}
