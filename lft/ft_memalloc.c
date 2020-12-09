/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:11:27 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 15:11:27 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *out;

	if (!(out = (unsigned char*)(malloc(sizeof(unsigned char) * size))))
		return (NULL);
	ft_bzero(out, size);
	return ((void*)out);
}
