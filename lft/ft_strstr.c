/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:27:03 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 15:27:03 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *substr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (substr[0] == '\0')
		return ((char*)src);
	while (src[i] != '\0')
	{
		if (src[i] == substr[j])
		{
			while (substr[j] == src[i + j] && substr[j] != '\0')
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
