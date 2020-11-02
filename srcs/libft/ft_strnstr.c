/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:33:43 by jabilbo           #+#    #+#             */
/*   Updated: 2019/09/20 23:31:34 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	j;
	size_t			q;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len != 0)
	{
		j = 0;
		q = len;
		while (*(needle + j) && (*(haystack + j) == *(needle + j)) && q != 0)
		{
			q--;
			j++;
		}
		if (*(needle + j) == '\0')
			return ((char *)(haystack));
		haystack++;
		len--;
	}
	return (NULL);
}
