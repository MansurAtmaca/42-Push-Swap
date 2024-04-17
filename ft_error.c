/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:58:56 by mansurcanat       #+#    #+#             */
/*   Updated: 2024/04/18 02:19:50 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_free_list(char **av, t_stack *stack, int control)
{
	int	a;

	a = 0;
	if (control == 2)
	{
		while (av[a])
		{
			free(av[a]);
			a++;
		}
		free(av);
	}
	free (stack->stack_a);
	free (stack->stack_b);
	free (stack);
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_free(char **argv, t_stack *stack, int control)
{
	int	i;

	i = 0;
	if (control == 2)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	free (stack->stack_a);
	free (stack->stack_a);
	free (stack);
	write(2, "Error\n", 6);
	exit (1);
}
