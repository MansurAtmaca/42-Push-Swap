/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:14:08 by matmaca           #+#    #+#             */
/*   Updated: 2024/04/18 09:42:12 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quicksort_a(t_stack *stack, int len, int count)
{
	int	pivot_a;
	int	items;

	if (is_sorted(stack->stack_a, len, 0) == 1)
		return (1);
	if (len == 2)
		return (sort_small_a(stack));
	else if (len == 3 && stack->size_a == 3)
		return (sort_three(stack));
	else if (len == 3)
		return (sort_medium_a(stack, len));
	find_pivot(&pivot_a, stack->stack_a, len);
	items = len;
	while (len != items / 2 + items % 2)
	{
		if (stack->stack_a[0] < pivot_a && (len--))
			pb(stack);
		else if (++count)
			ra(stack);
	}
	while (items / 2 + items % 2 != stack->size_a && count--)
		rra(stack);
	return (quicksort_a(stack, items / 2 + items % 2, 0),
		quicksort_b(stack, items / 2, 0));
}

int	quicksort_b(t_stack *stack, int len, int count)
{
	int	pivot_b;
	int	items;

	if (!count && is_sorted(stack->stack_b, len, 1) == 1)
		while (len--)
			pa(stack);
	if (len <= 3)
		return (sort_small_b(stack, len));
	find_pivot(&pivot_b, stack->stack_b, len);
	items = len;
	while (len != items / 2)
	{
		if (stack->stack_b[0] >= pivot_b && (len--))
			pa(stack);
		else if (++count)
			rb(stack);
	}
	while (items / 2 != stack->size_b && count--)
		rrb(stack);
	return (quicksort_a(stack, items / 2 + items % 2, 0),
		quicksort_b(stack, items / 2, 0));
	return (1);
}

int	ft_first_seperation(t_stack *stack, int len)
{
	int	pivot_a;
	int	pivot_b;
	int	items;

	items = len;
	find_pivot(&pivot_a, stack->stack_a, len);
	while (len != items / 2 + items % 2)
	{
		if (stack->stack_a[0] < pivot_a && (len--))
			pb(stack);
		else
		{
			find_pivot(&pivot_b, stack->stack_b, stack->size_b);
			if ((stack->stack_b[0] <= pivot_b) && (stack->size_b > 2))
				rr(stack, 0);
			else
				ra(stack);
		}
	}
	quicksort_a(stack, items / 2 + items % 2, 0);
	quicksort_b(stack, items / 2, 0);
	return (1);
}
