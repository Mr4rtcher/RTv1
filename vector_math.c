/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:16:26 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/12 07:30:05 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec		v_sub(t_vec *v1, t_vec *v2)
{
	t_vec	result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

double		v_dot(t_vec *v1, t_vec *v2)
{
	double	result;

	result = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (result);
}

t_vec		v_add(t_vec *v1, t_vec *v2)
{
	t_vec	result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

t_vec		v_scale(double c, t_vec *v)
{
	t_vec	result;

	result.x = v->x * c;
	result.y = v->y * c;
	result.z = v->z * c;
	return (result);
}

t_vec		v_cross(t_vec *v1, t_vec *v2)
{
	t_vec	result;

	result.x = v1->y * v2->z - v1->z * v2->y;
	result.y = v1->z * v2->x - v1->x * v2->z;
	result.z = v1->x * v2->y - v1->y * v2->x;
	return (result);
}
