/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:00:49 by aomega            #+#    #+#             */
/*   Updated: 2020/11/12 04:18:55 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		extra(double out, const char *str, int i)
{
	double	minor;
	double	ten;

	minor = 0;
	ten = 1;
	i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		ten = ten * 10;
		minor = minor + ((double)(str[i] - '0') / ten);
		i++;
	}
	return (out + minor);
}

double		ft_atof(const char *str)
{
	double	out;
	int		minus;
	int		i;

	minus = 1;
	out = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while ((str[i] && str[i] >= '0' && str[i] <= '9'))
	{
		out = out * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		out = extra(out, str, i);
	return (minus * out);
}
