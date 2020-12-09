/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:24:10 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 15:24:10 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmps1;
	unsigned char	*tmps2;
	size_t			i;

	tmps1 = (unsigned char*)s1;
	tmps2 = (unsigned char*)s2;
	i = 0;
	if (tmps1 == tmps2)
		return (0);
	while ((tmps1[i] || tmps2[i]) && i < n)
	{
		if (tmps1[i] != tmps2[i])
			return (tmps1[i] - tmps2[i]);
		i++;
	}
	return (0);
}
