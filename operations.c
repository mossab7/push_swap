/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:28:41 by mbouhia           #+#    #+#             */
/*   Updated: 2025/01/16 01:28:41 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p(t_vec *pop_stack, t_vec *push_stack, char *msg)
{
	if (is_empty(pop_stack))
		return (0);
	if (push(push_stack, pop(pop_stack)) == -1)
		return (-1);
	if (msg)
		ft_putstr_fd(msg, 1);
	return (0);
}

int	rr(t_vec *stack, char *msg)
{
	int	i;
	int	temp;

	if (stack->size < 2)
		return (0);
	i = stack->size - 1;
	temp = stack->vector[i];
	while (i > 0)
	{
		stack->vector[i] = stack->vector[i - 1];
		i--;
	}
	stack->vector[0] = temp;
	if (msg)
		ft_putstr_fd(msg, 1);
	return (0);
}

int	rrr(t_vec *stack, char *msg)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack->size < 2)
		return (0);
	tmp = stack->vector[0];
	while (i < stack->size - 1)
	{
		stack->vector[i] = stack->vector[i + 1];
		i++;
	}
	stack->vector[i] = tmp;
	if (msg)
		ft_putstr_fd(msg, 1);
	return (0);
}

int	swap(t_vec *stack, char *msg)
{
	int	tmp;

	if (stack->size < 2)
		return (0);
	tmp = stack->vector[stack->size - 1];
	stack->vector[stack->size - 1] = stack->vector[stack->size - 2];
	stack->vector[stack->size - 2] = tmp;
	if (msg)
		ft_putstr_fd(msg, 1);
	return (0);
}
