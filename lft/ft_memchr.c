/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:11:58 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 15:11:58 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	chr;
	size_t			i;

	src = (unsigned char*)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == chr)
			return ((void*)&src[i]);
		i++;
	}
	return (NULL);
}
