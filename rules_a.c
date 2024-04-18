/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 02:20:19 by matmaca           #+#    #+#             */
/*   Updated: 2024/04/18 09:38:01 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_stack *stack)
{
	int	tmp;

	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	write(1, "sa\n", 3);
}

void	ra(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = stack->stack_a[0];
	while (i < stack->size_a)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->stack_a[i - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rra(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->size_a - 1;
	tmp = stack->stack_a[i];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[i] = tmp;
	write(1, "rra\n", 4);
}

void	pa(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->size_b)
	{
		stack->size_a++;
		i = stack->size_a;
		while (--i > 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
		}
		stack->stack_a[0] = stack->stack_b[0];
		i = -1;
		stack->size_b--;
		while (++i < stack->size_b)
			stack->stack_b[i] = stack->stack_b[i + 1];
	}
	write(1, "pa\n", 3);
}
