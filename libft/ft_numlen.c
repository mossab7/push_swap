/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:21:14 by mbouhia           #+#    #+#             */
/*   Updated: 2025/01/14 14:21:16 by mbouhia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(long nb)
{
	int		sign;
	size_t	len;

	sign = (nb < 0);
	len = 0;
	if (nb == 0)
		return (1);
	if (sign)
		nb = -nb;
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len + sign);
}
