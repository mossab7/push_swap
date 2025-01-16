/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:28:42 by mbouhia           #+#    #+#             */
/*   Updated: 2025/01/16 01:28:42 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	is_valid_number(t_vec *vector, long num)
{
	int	i;

	if (num > INT_MAX || num < INT_MIN)
		return (-1);
	i = 0;
	while (i < vector->size)
	{
		if (vector->vector[i] == num)
			return (-1);
		i++;
	}
	return (0);
}

int	is_digits(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]) && number[i] != '-' && number[i] != '+')
			return (-1);
		i++;
	}
	return (0);
}

int	convert_to_int(t_vec *result, char **numbers)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	while (numbers[i])
		i++;
	if (i == 0)
		return (-1);
	j = 0;
	while (j < i)
	{
		if (is_digits(numbers[j]) == -1)
			return (-1);
		num = ft_atoi(numbers[j]);
		if (is_valid_number(result, num) == -1)
			return (-1);
		if (push(result, num) == -1)
			return (-1);
		j++;
	}
	return (0);
}

t_vec	*parse(int size, char **args)
{
	int		i;
	char	**numbers;
	t_vec	*result;

	i = 0;
	constructor(&result);
	if (!result)
		return (NULL);
	while (i < size)
	{
		numbers = ft_split(args[i], ' ');
		if (!numbers)
			return (NULL);
		if (convert_to_int(result, numbers) == -1)
			return (NULL);
		i++;
	}
	return (result);
}
