/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:15:09 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/12 07:12:01 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double			intersect_ray_cone(t_ray *r, t_obj *cone)
{
	double		a;
	double		b;
	double		discr;
	t_vec		oc;
	double		k;

	oc = v_sub(&r->start, &cone->position);
	v_normalize(&cone->axis);
	k = cone->radius / sqrt(v_dot(&cone->axis, &cone->axis));
	a = v_dot(&r->direction, &r->direction)
		- (1 + k * k) * pow(v_dot(&r->direction, &cone->axis), 2);
	b = 2 * (v_dot(&r->direction, &oc) - (1 + k * k)
		* v_dot(&r->direction, &cone->axis) * v_dot(&oc, &cone->axis));
	discr = b * b - 4 * a *
		(v_dot(&oc, &oc) - (1 + k * k) * pow(v_dot(&oc, &cone->axis), 2));
	return (t_calc(discr, a, b));
}

t_vec			cone_normal(t_vec *point, t_ray *r, t_obj *cone)
{
	t_vec		normal;
	t_vec		oc;
	t_vec		vm;
	double		k;
	double		m;

	oc = v_sub(&r->start, &cone->position);
	v_normalize(&cone->axis);
	k = cone->radius / sqrt(v_dot(&cone->axis, &cone->axis));
	m = (v_dot(point, &r->direction)
		* v_dot(&r->direction, &cone->axis)) + v_dot(&oc, &cone->axis);
	normal = v_sub(point, &cone->position);
	vm = v_scale(m, &cone->axis);
	vm = v_scale(1 + (k * k), &vm);
	normal = v_sub(&normal, &vm);
	v_normalize(&normal);
	return (normal);
}
