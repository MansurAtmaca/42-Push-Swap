/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:40:58 by matmaca           #+#    #+#             */
/*   Updated: 2024/04/18 14:06:12 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_len(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

void	ft_check_repeat(t_stack *stack, char **argv, int control)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
			{
				free_list(argv, stack, control);
			}
			j++;
		}
		i++;
	}
}

void	push_swap(t_stack *stack, char **argv, int size, int control)
{
	int		i;

	i = -1;
	while (++i < size)
		stack->stack_a[i] = ps_atoi(argv[i], stack, argv, control);
	ft_check_repeat(stack, argv, control);
	if (!is_sorted(stack->stack_a, size, 0))
		sort(stack, size);
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
}

void	create_stacks(char **argv, int control)
{
	t_stack	*stack;
	int		size;

	stack = malloc(sizeof(t_stack));
	size = find_len(argv);
	stack->stack_a = malloc(sizeof(int) * size);
	if (!stack->stack_a)
		free (stack);
	stack->size_a = size;
	stack->stack_b = malloc(sizeof(int) * size);
	if (!stack->stack_b)
	{
		free(stack->stack_a);
		return ;
	}
	stack->size_b = 0;
	push_swap(stack, argv, size, control);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		create_stacks(argv, 2);
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	else
	{
		create_stacks(++argv, 1);
	}
	return (0);
}
