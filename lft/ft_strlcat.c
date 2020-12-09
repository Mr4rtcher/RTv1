/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:22:44 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 15:22:46 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t len_d;
	size_t len_s;

	len_s = ft_strlen(src);
	len_d = ft_strnlen(dest, size);
	if (len_d == size)
		return (len_s + size);
	if (len_s < size - len_d)
		ft_strncpy(dest + len_d, src, len_s + 1);
	else
	{
		ft_strncpy(dest + len_d, src, size - len_d - 1);
		dest[size - 1] = '\0';
	}
	return (len_s + len_d);
}
