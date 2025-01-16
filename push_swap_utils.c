/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:28:42 by mbouhia           #+#    #+#             */
/*   Updated: 2025/01/16 01:28:42 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack(t_vec *sorted, t_vec *stack_a)
{
	int	i;

	i = sorted->size - 1;
	while (i >= 0)
	{
		push(stack_a, sorted->vector[i]);
		i--;
	}
}

int	get_pos(t_vec *stack_a, t_chunk *chunk)
{
	int	i;
	int	pos;

	pos = 0;
	i = stack_a->size - 1;
	while (i >= 0)
	{
		if (in_range(stack_a->vector[i], chunk->sorted, chunk->start,
				chunk->end))
			return (pos);
		i--;
		pos++;
	}
	return (-1);
}

int	get_max_pos(t_vec *stack_b, int max)
{
	int	i;
	int	pos;

	i = stack_b->size - 1;
	pos = 0;
	while (i >= 0)
	{
		if (stack_b->vector[i] == max)
			return (pos);
		i--;
		pos++;
	}
	return (-1);
}
