/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:51:30 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 15:32:31 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nmblen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		size;
	char	*out;
	long	ln;

	ln = (long)n;
	size = ft_nmblen(n);
	out = ft_strnew(size);
	if (!out)
		return (NULL);
	if (ln == 0)
		out[0] = '0';
	if (ln < 0)
	{
		out[0] = '-';
		ln = -ln;
	}
	while (size > 0 && ln > 0)
	{
		out[size - 1] = (char)('0' + ln % 10);
		ln = ln / 10;
		size--;
	}
	return (out);
}
