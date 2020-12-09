/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:12:13 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 15:12:13 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!src && !dest)
		return (dest);
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		*(d++) = *(s++);
		i++;
	}
	return (dest);
}
