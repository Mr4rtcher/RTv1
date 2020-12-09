/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math_dop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 07:28:32 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/12 09:23:44 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		v_length(t_vec *v)
{
	return (sqrt(v_dot(v, v)));
}

void		v_normalize(t_vec *v)
{
	double len;

	len = v_length(v);
	v->x /= len;
	v->y /= len;
	v->z /= len;
}

t_vec		v_invert(t_vec *v)
{
	t_vec	zero;

	zero.x = 0;
	zero.y = 0;
	zero.z = 0;
	return (v_sub(&zero, v));
}

void		argb_what(t_vec *argb)
{
	argb->x = ft_clamp(argb->x, 0, 255);
	argb->y = ft_clamp(argb->y, 0, 255);
	argb->z = ft_clamp(argb->z, 0, 255);
}
