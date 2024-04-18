/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:29:19 by matmaca           #+#    #+#             */
/*   Updated: 2024/04/18 09:38:07 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ss(t_stack	*s, int print)
{
	int	tmp;

	tmp = 0;
	tmp = s->stack_a[0];
	s->stack_a[0] = s->stack_a[1];
	s->stack_a[1] = tmp;
	tmp = s->stack_b[0];
	s->stack_b[0] = s->stack_b[1];
	s->stack_b[1] = tmp;
	if (!print)
		write(1, "ss\n", 3);
}

void	rr(t_stack	*s, int print)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->stack_a[i];
	while (++i < s->size_a)
		s->stack_a[i - 1] = s->stack_a[i];
	s->stack_a[i - 1] = tmp;
	i = 0;
	tmp = s->stack_b[i];
	while (++i < s->size_b)
		s->stack_b[i - 1] = s->stack_b[i];
	s->stack_b[i - 1] = tmp;
	if (!print)
		write(1, "rr\n", 3);
}
