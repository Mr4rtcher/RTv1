/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:51:41 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 14:52:25 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_array_size(char const *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s[i] != c && s[i])
		j++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			j++;
		i++;
	}
	return (j);
}

static int		ft_strlen_sym(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**out;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	out = (char **)ft_memalloc(sizeof(char*) * (ft_array_size(s, c) + 1));
	if (!out)
		return (NULL);
	while (j < ft_array_size(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		out[j] = ft_strsub(s, i, ft_strlen_sym(s + i, c));
		j++;
		i = i + ft_strlen_sym(s + i, c);
	}
	return (out);
}
