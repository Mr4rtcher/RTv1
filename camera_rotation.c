/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 07:28:32 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/12 09:23:44 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec	cam_vect_mult(t_vec cross_x, t_vec cross_y, t_vec dir, t_vec init_dir)
{
	t_vec out;

	out.x = cross_x.x * init_dir.x + cross_y.x * init_dir.y +
			dir.x * init_dir.z;
	out.y = cross_x.y * init_dir.x + cross_y.y * init_dir.y +
			dir.y * init_dir.z;
	out.z = cross_x.z * init_dir.x + cross_y.z * init_dir.y +
			dir.z * init_dir.z;
	return (out);
}

t_vec	optional_cam_dir(t_rt *rt, t_vec dir, int x, int y)
{
	t_vec out;
	t_vec init_vert;
	t_vec init_dir;
	t_vec cross_y;
	t_vec cross_x;

	init_vert.x = 1;
	init_vert.y = 0;
	init_vert.z = 0;
	init_dir.x = (((double)x + 0.5) / (double)rt->w) - 0.5;
	init_dir.y = (((double)y + 0.5) / (double)rt->h) - 0.5;
	init_dir.z = 1;
	v_normalize(&init_dir);
	cross_y = v_cross(&init_vert, &dir);
	v_normalize(&cross_y);
	cross_x = v_cross(&cross_y, &dir);
	v_normalize(&cross_x);
	out = cam_vect_mult(cross_x, cross_y, dir, init_dir);
	out.x = -out.x;
	v_normalize(&out);
	return (out);
}

t_vec	camera_dir(t_rt *rt, t_vec dir, int x, int y)
{
	t_vec out;
	t_vec init_vert;
	t_vec init_dir;
	t_vec cross_y;
	t_vec cross_x;

	if (dir.y == 1 || dir.y == -1)
	{
		out = optional_cam_dir(rt, dir, x, y);
		return (out);
	}
	init_vert.x = 0;
	init_vert.y = 1;
	init_vert.z = 0;
	init_dir.x = (((double)x + 0.5) / (double)rt->w) - 0.5;
	init_dir.y = (((double)y + 0.5) / (double)rt->h) - 0.5;
	init_dir.z = 1;
	v_normalize(&init_dir);
	cross_x = v_cross(&init_vert, &dir);
	v_normalize(&cross_x);
	cross_y = v_cross(&cross_x, &dir);
	v_normalize(&cross_y);
	out = cam_vect_mult(cross_x, cross_y, dir, init_dir);
	v_normalize(&out);
	return (out);
}
