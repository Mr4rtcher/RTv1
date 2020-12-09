/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:15:57 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/12 07:23:46 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		read_spheres(t_rt *rt, char *str)
{
	t_obj	*sp;
	t_obj	*tmp;

	sp = malloc(sizeof(t_obj));
	sp->next = NULL;
	if (rt->obj_lst == NULL)
		rt->obj_lst = sp;
	else
	{
		tmp = rt->obj_lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = sp;
	}
	read_sp_input(sp, str, rt);
}

void		read_planes(t_rt *rt, char *str)
{
	t_obj	*plane;
	t_obj	*tmp;

	plane = malloc(sizeof(t_obj));
	plane->next = NULL;
	if (rt->obj_lst == NULL)
		rt->obj_lst = plane;
	else
	{
		tmp = rt->obj_lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = plane;
	}
	read_pl_input(plane, str, rt);
}

void		read_cylinders(t_rt *rt, char *str)
{
	t_obj	*cyl;
	t_obj	*tmp;

	cyl = malloc(sizeof(t_obj));
	cyl->next = NULL;
	if (rt->obj_lst == NULL)
		rt->obj_lst = cyl;
	else
	{
		tmp = rt->obj_lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = cyl;
	}
	read_cyl_input(cyl, str, rt);
}

void		read_cones(t_rt *rt, char *str)
{
	t_obj	*cone;
	t_obj	*tmp;

	cone = malloc(sizeof(t_obj));
	cone->next = NULL;
	if (rt->obj_lst == NULL)
		rt->obj_lst = cone;
	else
	{
		tmp = rt->obj_lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = cone;
	}
	read_cone_input(cone, str, rt);
}

void		read_lights(t_rt *rt, char *str)
{
	t_light	*light;
	t_light	*tmp;

	light = malloc(sizeof(t_light));
	light->next = NULL;
	if (rt->light_lst == NULL)
		rt->light_lst = light;
	else
	{
		tmp = rt->light_lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = light;
	}
	read_light_input(light, str, rt);
}
