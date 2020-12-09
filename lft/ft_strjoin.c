/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:22:32 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 15:40:21 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	out = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!out)
		return (NULL);
	out = ft_strcpy(out, s1);
	out = ft_strcat(out, s2);
	return (out);
}
