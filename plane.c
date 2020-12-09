/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:16:02 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/12 07:18:12 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		intersect_ray_plane(t_ray *r, t_obj *plane)
{
	t_vec	oc;
	double	out;
	double	oc_v;
	double	d_v;

	oc = v_sub(&r->start, &plane->position);
	v_normalize(&plane->axis);
	oc_v = v_dot(&oc, &plane->axis);
	d_v = v_dot(&r->direction, &plane->axis);
	if (d_v == 0)
		return (0);
	else if (d_v < 0)
	{
		v_invert(&plane->axis);
		d_v = v_dot(&r->direction, &plane->axis);
	}
	out = oc_v * -1 / d_v;
	return (out);
}

t_vec		plane_normal(t_vec *point, t_ray *r, t_obj *plane)
{
	t_vec	*tmp;
	t_ray	*ex;

	ex = r;
	ex++;
	tmp = point;
	tmp++;
	return (plane->axis);
}
