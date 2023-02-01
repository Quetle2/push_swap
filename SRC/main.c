/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miandrad <miandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:40:55 by miandrad          #+#    #+#             */
/*   Updated: 2023/02/01 16:48:38 by miandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	take_input(&a, argc, argv);
	if (argc <= 4)
		trhee(&a);
	// while (a.head)
	// {
	// 	ft_printf("%i\n", *(int *)a.head->content);
	// 	a.head = a.head->next;
	// }
	free_malloooc(&a);
}

void	take_input(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	*nbr;

	i = 1;
	if (!check_nbr(argc, argv))
		return ;
	while (i < argc)
	{
		nbr = malloc(sizeof(int));
		*nbr = ft_atoi(argv[i]);
		ft_lstadd_back(&stack->head, ft_lstnew(nbr));
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

void	free_malloooc(t_stack *stack)
{
	ft_lstclear(&stack->head, free);
}
