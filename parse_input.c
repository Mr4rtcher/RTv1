/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:15:52 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/12 06:26:57 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		read_sp_input(t_obj *sp, char *str, t_rt *rt)
{
	char	**splitted_str;
	char	**pos;
	char	**color;

	splitted_str = ft_strsplit(str, ' ');
	check_data(splitted_str, rt);
	pos = ft_strsplit(splitted_str[1], ',');
	color = ft_strsplit(splitted_str[2], ',');
	sp->position = v_check(pos, rt);
	sp->color = v_check(color, rt);
	sp->radius = check_value(splitted_str[3], rt);
	sp->type = "sphere";
	free_splitted_str(pos);
	free_splitted_str(color);
	free_splitted_str(splitted_str);
}

void		read_pl_input(t_obj *plane, char *str, t_rt *rt)
{
	char	**splitted_str;
	char	**pos;
	char	**color;
	char	**axis;

	splitted_str = ft_strsplit(str, ' ');
	check_data(splitted_str, rt);
	pos = ft_strsplit(splitted_str[1], ',');
	color = ft_strsplit(splitted_str[2], ',');
	axis = ft_strsplit(splitted_str[3], ',');
	plane->position = v_check(pos, rt);
	plane->color = v_check(color, rt);
	plane->axis = v_check(axis, rt);
	plane->type = "plane";
	free_splitted_str(pos);
	free_splitted_str(color);
	free_splitted_str(axis);
	free_splitted_str(splitted_str);
}

void		read_cyl_input(t_obj *cyl, char *str, t_rt *rt)
{
	char	**splitted_str;
	char	**pos;
	char	**color;
	char	**axis;

	splitted_str = ft_strsplit(str, ' ');
	check_data(splitted_str, rt);
	pos = ft_strsplit(splitted_str[1], ',');
	color = ft_strsplit(splitted_str[2], ',');
	axis = ft_strsplit(splitted_str[3], ',');
	cyl->position = v_check(pos, rt);
	cyl->color = v_check(color, rt);
	cyl->axis = v_check(axis, rt);
	v_normalize(&cyl->axis);
	cyl->radius = check_value(splitted_str[4], rt);
	cyl->type = "cylinder";
	free_splitted_str(pos);
	free_splitted_str(color);
	free_splitted_str(axis);
	free_splitted_str(splitted_str);
}

void		read_cone_input(t_obj *cone, char *str, t_rt *rt)
{
	char	**splitted_str;
	char	**pos;
	char	**color;
	char	**axis;

	splitted_str = ft_strsplit(str, ' ');
	check_data(splitted_str, rt);
	pos = ft_strsplit(splitted_str[1], ',');
	color = ft_strsplit(splitted_str[2], ',');
	axis = ft_strsplit(splitted_str[3], ',');
	cone->position = v_check(pos, rt);
	cone->color = v_check(color, rt);
	cone->axis = v_check(axis, rt);
	v_normalize(&cone->axis);
	cone->radius = check_value(splitted_str[4], rt);
	cone->type = "cone";
	free_splitted_str(pos);
	free_splitted_str(color);
	free_splitted_str(axis);
	free_splitted_str(splitted_str);
}

void		read_light_input(t_light *light, char *str, t_rt *rt)
{
	char	**splitted_str;
	char	**pos;
	char	**spec_color;

	splitted_str = ft_strsplit(str, ' ');
	check_data(splitted_str, rt);
	pos = ft_strsplit(splitted_str[1], ',');
	spec_color = ft_strsplit(splitted_str[2], ',');
	light->position = v_check(pos, rt);
	light->spec_color = v_check(spec_color, rt);
	light->intensity = check_value(splitted_str[3], rt);
	light->spec_power = check_value(splitted_str[4], rt);
	free_splitted_str(pos);
	free_splitted_str(spec_color);
	free_splitted_str(splitted_str);
}
