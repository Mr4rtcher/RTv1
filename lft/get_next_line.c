/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomega <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:27:41 by aomega            #+#    #+#             */
/*   Updated: 2019/12/01 19:41:34 by aomega           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_line	*list_new(const int fd)
{
	t_line *new_el;

	if (!(new_el = (t_line *)ft_memalloc(sizeof(t_line))))
		return (NULL);
	new_el->fd = fd;
	new_el->leftover = NULL;
	new_el->next = NULL;
	return (new_el);
}

static	char	*chk_leftover(char *leftover, char **line)
{
	char *n_ptr;

	n_ptr = NULL;
	if (leftover)
	{
		if ((n_ptr = ft_strchr(leftover, '\n')))
		{
			*n_ptr = '\0';
			*line = ft_strdup(leftover);
			n_ptr++;
			ft_strcpy(leftover, n_ptr);
		}
		else
		{
			*line = ft_strdup(leftover);
			ft_strclr(leftover);
		}
	}
	else
		*line = ft_strnew(1);
	return (n_ptr);
}

static	int		gnl_single_fd(const int fd, char **line, char **leftover)
{
	int		i;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*n_pointer;

	i = 1;
	n_pointer = chk_leftover(*leftover, line);
	while (!n_pointer && (i = read(fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		if ((n_pointer = ft_strchr(buf, '\n')))
		{
			*n_pointer = '\0';
			n_pointer++;
			str = *leftover;
			*leftover = ft_strdup(n_pointer);
			ft_strdel(&str);
		}
		str = *line;
		if (!(*line = ft_strjoin(*line, buf)) || i < 0)
			return (-1);
		ft_strdel(&str);
	}
	return (i || ft_strlen(*line) || ft_strlen(*leftover) ? 1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*list;
	t_line			*tmp;
	int				out;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	if (list == NULL)
		list = list_new(fd);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = list_new(fd);
		tmp = tmp->next;
	}
	out = gnl_single_fd(fd, line, &tmp->leftover);
	return (out);
}
