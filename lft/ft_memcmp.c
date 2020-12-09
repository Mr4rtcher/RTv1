/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:12:06 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 15:12:06 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmps1;
	unsigned char	*tmps2;
	size_t			i;

	tmps1 = (unsigned char*)s1;
	tmps2 = (unsigned char*)s2;
	i = 0;
	if (s1 == s2)
		return (0);
	while (i < n)
	{
		if (tmps1[i] != tmps2[i])
			return (tmps1[i] - tmps2[i]);
		i++;
	}
	return (0);
}
