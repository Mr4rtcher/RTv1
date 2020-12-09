/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:15:21 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/12 06:45:48 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double			intersect_ray_cylinder(t_ray *r, t_obj *cyl)
{
	double		a;
	double		b;
	double		c;
	double		discr;
	t_vec		oc;

	oc = v_sub(&r->start, &cyl->position);
	v_normalize(&cyl->axis);
	a = v_dot(&r->direction, &r->direction)
		- pow(v_dot(&r->direction, &cyl->axis), 2);
	b = 2 * (v_dot(&r->direction, &oc)
		- v_dot(&r->direction, &cyl->axis) * v_dot(&oc, &cyl->axis));
	c = v_dot(&oc, &oc)
		- pow(v_dot(&oc, &cyl->axis), 2) - cyl->radius * cyl->radius;
	discr = b * b - 4 * a * c;
	return (t_calc(discr, a, b));
}

t_vec			cylinder_normal(t_vec *point, t_ray *r, t_obj *cyl)
{
	t_vec		normal;
	t_vec		oc;
	t_vec		vm;
	double		dv;
	double		m;

	oc = v_sub(&r->start, &cyl->position);
	v_normalize(&cyl->axis);
	dv = v_dot(&r->direction, &cyl->axis);
	m = (v_dot(point, &r->direction) * dv) + v_dot(&oc, &cyl->axis);
	normal = v_sub(point, &cyl->position);
	vm = v_scale(m, &cyl->axis);
	normal = v_sub(&normal, &vm);
	v_normalize(&normal);
	return (normal);
}
