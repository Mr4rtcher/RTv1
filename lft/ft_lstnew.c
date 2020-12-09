/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <aomega@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:11:17 by aomega            #+#    #+#             */
/*   Updated: 2019/09/29 15:11:17 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *out;

	if (!(out = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		out->content = NULL;
		out->content_size = 0;
	}
	else
	{
		out->content = ft_memalloc(content_size);
		out->content_size = content_size;
		ft_memcpy(out->content, content, content_size);
	}
	out->next = NULL;
	return (out);
}
