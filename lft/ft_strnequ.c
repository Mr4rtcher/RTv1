/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:24:57 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 15:24:57 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int cmp;

	if (!s1 || !s2)
		return (0);
	cmp = ft_strncmp(s1, s2, n);
	return ((cmp == 0) ? 1 : 0);
}
