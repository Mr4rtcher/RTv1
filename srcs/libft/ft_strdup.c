/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:43:31 by jabilbo           #+#    #+#             */
/*   Updated: 2019/09/18 03:11:19 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*bax;
	int		i;
	int		size;

	size = 0;
	while (s1[size])
		++size;
	if (!(bax = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		bax[i] = s1[i];
		i++;
	}
	bax[i] = '\0';
	return (bax);
}
