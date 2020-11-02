/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:28:04 by jabilbo           #+#    #+#             */
/*   Updated: 2019/09/21 20:31:27 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned char *box;

	if (size + 1 == 0)
		return (NULL);
	box = (unsigned char *)malloc(sizeof(char) * (size + 1));
	if (NULL == box)
		return (NULL);
	*box = '\0';
	while (size != 0)
	{
		*(box + size) = '\0';
		size--;
	}
	return ((char *)box);
}
