/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:16:21 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/12 06:12:26 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		intersect_ray_sphere(t_ray *r, t_obj *sp)
{
	double	a;
	double	b;
	double	c;
	t_vec	sp_distance;
	double	discr;

	a = v_dot(&r->direction, &r->direction);
	sp_distance = v_sub(&r->start, &sp->position);
	b = 2 * v_dot(&r->direction, &sp_distance);
	c = v_dot(&sp_distance, &sp_distance) - (sp->radius * sp->radius);
	discr = b * b - 4 * a * c;
	return (t_calc(discr, a, b));
}

double		t_calc(double discr, double a, double b)
{
	double	t1;
	double	t2;

	if (discr < 0)
		return (0);
	else
	{
		t1 = (-b + sqrt(discr)) / (2 * a);
		t2 = (-b - sqrt(discr)) / (2 * a);
		if (t2 > t1)
			return (t1);
		else
			return (t2);
	}
}

t_vec		sphere_normal(t_vec *point, t_ray *r, t_obj *sphere)
{
	t_vec	normal;
	t_obj	*tmp;
	t_ray	*ex;

	ex = r;
	ex++;
	tmp = sphere;
	normal = v_sub(point, &tmp->position);
	v_normalize(&normal);
	return (normal);
}
