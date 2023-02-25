/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:04:41 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/25 18:49:57 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stack_init(t_stack *stack, int argc)
{
	stack->head = NULL;
	stack->size = argc - 1;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	stack_init(&a, argc);
	stack_init(&b, argc);
	if (!take_input(&a, argc, argv))
	{
		ft_printf("Error\n");
		ft_lstclear(&(&a)->head, free);
		return (0);
	}
	if (!replicate(&(&a)->head, &(&b)->head))
		ft_printf("Error\n");
	else if (check_order((&a)->head))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&(&a)->head, free);
}

int	take_input(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	*nbr;

	i = 1;
	if (!check_nbr(argc, argv))
		return (0);
	while (i < argc)
	{
		nbr = malloc(sizeof(int));
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		*nbr = ft_atoi(argv[i]);
		if (!duplicate(stack->head, nbr))
			ft_lstadd_back(&stack->head, ft_lstnew(nbr));
		else
			return (0);
		i++;
	}
	return (1);
}

int	duplicate(t_list *list, int *nbr)
{
	while (list)
	{
		if (*nbr == *list->content)
			return (1);
		list = list->next;
	}
	return (0);
}

int	check_nbr(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57)
				&& argv[i][j] != '-' && argv[i][j] != '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
