/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:28:42 by mbouhia           #+#    #+#             */
/*   Updated: 2025/01/16 01:28:42 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_vec *stack)
{
	int	i;
	int	target_idx;
	int	target;
	int	j;

	j = 0;
	target = stack->vector[0];
	target_idx = 0;
	i = stack->size - 1;
	while (i >= 0)
	{
		if (stack->vector[i] <= target)
		{
			target = stack->vector[i];
			target_idx = j;
		}
		j++;
		i--;
	}
	return (target_idx);
}

void	sort_three(t_vec *stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = stack_a->vector[2];
	mid = stack_a->vector[1];
	bot = stack_a->vector[0];
	if (top > mid && mid < bot && top < bot)
		execute(stack_a, NULL, SA);
	else if (top > mid && mid > bot)
	{
		execute(stack_a, NULL, SA);
		execute(stack_a, NULL, RRA);
	}
	else if (top > mid && mid < bot && top > bot)
		execute(stack_a, NULL, RA);
	else if (top < mid && mid > bot && top < bot)
	{
		execute(stack_a, NULL, SA);
		execute(stack_a, NULL, RA);
	}
	else if (top < mid && mid > bot && top > bot)
		execute(stack_a, NULL, RRA);
}

int	sort_five(t_vec *stack_a, t_vec *stack_b)
{
	int	idx;
	int	i;

	i = 0;
	while (i < 2)
	{
		idx = get_index(stack_a);
		if (idx == stack_a->size - 1)
			execute(stack_a, NULL, RRA);
		else
		{
			while (idx > 0)
			{
				execute(stack_a, stack_b, RA);
				idx--;
			}
		}
		execute(stack_a, stack_b, PB);
		i++;
	}
	sort_three(stack_a);
	execute(stack_a, stack_b, PA);
	execute(stack_a, stack_b, PA);
	return (0);
}
