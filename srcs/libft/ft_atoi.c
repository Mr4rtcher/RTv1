/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:57:09 by jabilbo           #+#    #+#             */
/*   Updated: 2019/09/20 20:37:40 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long	nb;
	int			negative;

	nb = 0;
	negative = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (nb > nb * 10 + (*str - '0'))
		{
			if (negative == -1)
				return (0);
			else
				return (-1);
		}
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * negative);
}
