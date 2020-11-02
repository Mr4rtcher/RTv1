/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 01:24:37 by jabilbo           #+#    #+#             */
/*   Updated: 2019/09/20 01:54:04 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					i;
	unsigned char			*s1;
	const unsigned char		*s2;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (s1 == s2)
		return (dst);
	if (s2 < s1)
		while (++i <= len)
			s1[len - i] = s2[len - i];
	else
		while (len-- > 0)
			*(s1++) = *(s2++);
	return (dst);
}
