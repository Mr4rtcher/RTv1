/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:12:30 by jabilbo           #+#    #+#             */
/*   Updated: 2019/09/21 20:14:34 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *box;

	box = (unsigned char *)malloc(size);
	if (NULL == box)
		return (NULL);
	while (size != 0)
	{
		size--;
		*(box + size) = 0;
	}
	return ((void *)box);
}
