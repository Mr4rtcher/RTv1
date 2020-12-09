/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 07:28:32 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/12 09:23:44 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		assign_func(t_rt *rt, t_ray *r, t_obj *obj)
{
	r->obj = obj;
	if (ft_strcmp(r->obj->type, "sphere") == 0)
		rt->norm_func = sphere_normal;
	else if (ft_strcmp(r->obj->type, "plane") == 0)
		rt->norm_func = plane_normal;
	else if (ft_strcmp(r->obj->type, "cylinder") == 0)
		rt->norm_func = cylinder_normal;
	else if (ft_strcmp(r->obj->type, "cone") == 0)
		rt->norm_func = cone_normal;
}

double		isec_obj_type(t_ray *r, t_obj *obj)
{
	double out;

	out = 0;
	if (ft_strcmp(obj->type, "sphere") == 0)
		out = intersect_ray_sphere(r, obj);
	else if (ft_strcmp(obj->type, "plane") == 0)
		out = intersect_ray_plane(r, obj);
	else if (ft_strcmp(obj->type, "cylinder") == 0)
		out = intersect_ray_cylinder(r, obj);
	else if (ft_strcmp(obj->type, "cone") == 0)
		out = intersect_ray_cone(r, obj);
	return (out);
}

double		intersect_objs(t_rt *rt, t_ray *r)
{
	double	out;
	double	tmp;
	t_obj	*obj;

	obj = rt->obj_lst;
	out = 0;
	while (obj != NULL)
	{
		if (!ft_strcmp(r->type, "shadow") && obj == r->obj)
		{
			if (obj->next == NULL)
				return (out);
			obj = obj->next;
		}
		tmp = isec_obj_type(r, obj);
		if (tmp > 0 && (tmp < out || out == 0))
		{
			out = tmp;
			if (!ft_strcmp(r->type, "vision"))
				assign_func(rt, r, obj);
		}
		obj = obj->next;
	}
	return (out);
}
