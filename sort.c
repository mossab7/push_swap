/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:28:42 by mbouhia           #+#    #+#             */
/*   Updated: 2025/01/16 01:28:42 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_p(t_vec *stack)
{
	int	i;

	i = stack->size - 1;
	while (i >= 0)
	{
		printf("%d\n", stack->vector[i]);
		i--;
	}
}

void	push_to_b(t_vec *stack_a, t_vec *stack_b, t_chunk *chunk)
{
	int	pos;

	while (!is_empty(stack_a))
	{
		pos = get_pos(stack_a, chunk);
		while (pos > 0)
		{
			execute(stack_a, stack_b, RA);
			pos--;
		}
		execute(stack_a, stack_b, PB);
		if (in_range(stack_b->vector[stack_b->size - 1], chunk->sorted,
				chunk->start, chunk->mid - 1))
			execute(stack_a, stack_b, RB);
		update_offset(chunk, stack_b);
	}
}

void	fetch_max_element(t_vec *stack_a, t_vec *stack_b, t_chunk *chunk)
{
	if (chunk->max == stack_b->vector[stack_b->size - 1])
	{
		execute(stack_a, stack_b, PA);
		chunk->sorted->size -= 1;
	}
	else if (chunk->down == 0 || stack_b->vector[stack_b->size
			- 1] > stack_a->vector[0])
	{
		execute(stack_a, stack_b, PA);
		execute(stack_a, stack_b, RA);
		chunk->down++;
	}
	else
	{
		if (chunk->pos <= stack_b->size / 2)
			execute(stack_a, stack_b, RB);
		else
			execute(stack_a, stack_b, RRB);
	}
}

void	push_back_to_a(t_vec *stack_a, t_vec *stack_b, t_chunk *chunk)
{
	chunk->down = 0;
	while (!is_empty(stack_b))
	{
		chunk->max = chunk->sorted->vector[chunk->sorted->size - 1];
		chunk->pos = get_max_pos(stack_b, chunk->max);
		if (chunk->pos >= 0)
		{
			fetch_max_element(stack_a, stack_b, chunk);
		}
		else
		{
			execute(stack_a, stack_b, RRA);
			chunk->down--;
			chunk->sorted->size -= 1;
		}
	}
	while (chunk->down--)
		execute(stack_a, stack_b, RRA);
}

void	sort(t_chunk *chunk)
{
	t_vec	*stack_a;
	t_vec	*stack_b;

	constructor(&stack_a);
	constructor(&stack_b);
	push_to_stack(chunk->sorted, stack_a);
	stack_sort(chunk->sorted);
	init_chunk(chunk);
	if (stack_a->size == 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (stack_a->size == 5)
	{
		sort_five(stack_a, stack_b);
		return ;
	}
	push_to_b(stack_a, stack_b, chunk);
	push_back_to_a(stack_a, stack_b, chunk);
}
