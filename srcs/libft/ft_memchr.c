/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 01:57:01 by jabilbo           #+#    #+#             */
/*   Updated: 2019/09/20 02:20:04 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	cr;

	i = 0;
	cr = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (str[i] == cr)
			return (str + i);
		i++;
	}
	return (NULL);
}
