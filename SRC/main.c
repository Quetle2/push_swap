/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:40:55 by miandrad          #+#    #+#             */
/*   Updated: 2023/01/31 17:43:36 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_init(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	stack_init(&a);
	stack_init(&b);
	take_input(&a, argc, argv);
	sa(&a);
}

void	take_input(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	nbr;

	i = 1;
	if (!check_nbr(argc, argv))
		return ;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		ft_lstadd_back(&stack->head, ft_lstnew(&nbr));
		i++;
	}
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
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
