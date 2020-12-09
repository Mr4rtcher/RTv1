/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:50:28 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 14:50:43 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*out;
	size_t	i;

	i = 0;
	if (!(out = (char*)(malloc(sizeof(char) * (size + 1)))))
		return (NULL);
	while (i < size + 1)
	{
		out[i] = '\0';
		i++;
	}
	return (out);
}
