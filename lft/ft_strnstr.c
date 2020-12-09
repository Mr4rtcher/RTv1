/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:25:34 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 15:25:34 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *substr, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (substr[0] == '\0')
		return ((char*)src);
	while (src[i] != '\0' && i < n)
	{
		if (src[i] == substr[j])
		{
			while (substr[j] == src[i + j] && substr[j] != '\0' && i + j < n)
			{
				j++;
				if (substr[j] == '\0')
					return ((char*)&src[i]);
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}
