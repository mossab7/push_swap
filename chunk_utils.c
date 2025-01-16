/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:28:41 by mbouhia           #+#    #+#             */
/*   Updated: 2025/01/16 01:28:41 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_chunk(t_chunk *chunk)
{
	if (chunk->sorted->size <= 10)
		chunk->offset = chunk->sorted->size / 5;
	else if (chunk->sorted->size <= 150)
		chunk->offset = chunk->sorted->size / 8;
	else
		chunk->offset = chunk->sorted->size / 18;
	chunk->mid = chunk->sorted->size / 2;
	chunk->start = chunk->mid - chunk->offset;
	chunk->end = chunk->mid + chunk->offset;
}

void	update_offset(t_chunk *chunk, t_vec *stack_b)
{
	if (all_in_range(chunk->sorted, chunk->start, chunk->mid, stack_b))
	{
		if (chunk->start - chunk->offset < 0)
			chunk->start = 0;
		else
			chunk->start -= chunk->offset;
	}
	if (all_in_range(chunk->sorted, chunk->mid + 1, chunk->end, stack_b))
	{
		if (chunk->end + chunk->offset > chunk->sorted->size - 1)
			chunk->end = chunk->sorted->size - 1;
		else
			chunk->end += chunk->offset;
	}
}

void	stack_sort(t_vec *stack)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->vector[i] > stack->vector[j])
			{
				temp = stack->vector[i];
				stack->vector[i] = stack->vector[j];
				stack->vector[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	all_in_range(t_vec *sorted, int start, int end, t_vec *stack_b)
{
	int	i;
	int	j;
	int	found;

	i = start;
	while (i <= end)
	{
		j = 0;
		found = 0;
		while (j < stack_b->size)
		{
			if (stack_b->vector[j] == sorted->vector[i])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (!found)
			return (0);
		i++;
	}
	return (1);
}

int	in_range(int value, t_vec *sorted, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (value == sorted->vector[i])
			return (1);
		i++;
	}
	return (0);
}
