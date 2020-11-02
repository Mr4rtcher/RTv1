/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 23:00:19 by jabilbo           #+#    #+#             */
/*   Updated: 2019/09/18 22:46:10 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		h;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		h = 0;
		while (needle[h] == haystack[i + h])
		{
			if (needle[h + 1] == '\0')
				return ((char *)&haystack[i]);
			h++;
		}
		i++;
	}
	return (0);
}
