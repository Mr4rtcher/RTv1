/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:15:52 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/12 06:26:57 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		read_camera(t_rt *rt, char *str)
{
	char	**splitted_str;
	char	**pos;
	char	**dir;

	splitted_str = ft_strsplit(str, ' ');
	check_data(splitted_str, rt);
	pos = ft_strsplit(splitted_str[1], ',');
	dir = ft_strsplit(splitted_str[2], ',');
	rt->cam_pos = v_check(pos, rt);
	rt->cam_dir = v_check(dir, rt);
	free_splitted_str(pos);
	free_splitted_str(dir);
	free_splitted_str(splitted_str);
	if (rt->cam_pos.x == rt->cam_dir.x && rt->cam_pos.y == rt->cam_dir.y &&
			rt->cam_pos.z == rt->cam_dir.z)
		quit("invalid camera direction\n", rt);
}

void		read_values(t_rt *rt, int fd)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strnequ(line, "camera:", 7))
			read_camera(rt, line);
		else if (ft_strnequ(line, "sphere:", 7))
			read_spheres(rt, line);
		else if (ft_strnequ(line, "plane:", 6))
			read_planes(rt, line);
		else if (ft_strnequ(line, "cylinder:", 9))
			read_cylinders(rt, line);
		else if (ft_strnequ(line, "cone:", 5))
			read_cones(rt, line);
		else if (ft_strnequ(line, "light:", 6))
			read_lights(rt, line);
		free(line);
	}
	free(line);
}

void		free_light_list(t_light *l_list)
{
	t_light	*tmp;

	while (l_list != NULL)
	{
		tmp = l_list->next;
		free(l_list);
		l_list = tmp;
	}
}

void		free_obj_list(t_obj *obj_list)
{
	t_obj	*tmp;

	while (obj_list != NULL)
	{
		tmp = obj_list->next;
		free(obj_list);
		obj_list = tmp;
	}
}

void		free_lists(t_rt *rt)
{
	free_light_list(rt->light_lst);
	free_obj_list(rt->obj_lst);
}
