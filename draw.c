/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:15:28 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/12 09:23:32 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		calculate_diffuse_light(t_rt *rt, t_light *light, t_ray *ray)
{
	double	scale_value;
	t_vec	scaled_ray;
	t_vec	intersection_point;
	t_vec	light_v;
	t_vec	tmp;
	double	out;

	scale_value = intersect_objs(rt, ray);
	if (scale_value == 0)
		return (0);
	scaled_ray = v_scale(scale_value, &ray->direction);
	intersection_point = v_add(&ray->start, &scaled_ray);
	light_v = v_sub(&light->position, &intersection_point);
	light->sh_v_len = v_length(&light_v);
	v_normalize(&light_v);
	tmp = v_scale(0.001,&light_v);
	light->normal = rt->norm_func(&intersection_point, ray, ray->obj);
	light->isec_point_to_light.start =
			v_add(&intersection_point, &tmp);
	light->isec_point_to_light.direction = light_v;
	light->isec_point_to_light.type = "shadow";
	light->isec_point_to_light.obj = ray->obj;
	light->shadow_isec = intersect_objs(rt, &light->isec_point_to_light);
	out = v_dot(&light->normal, &light_v) * light->intensity;
	out = out > 0 ? out : 0;
	return (out);
}

double		calculate_spec_light(t_light *light, t_ray *ray)
{
	t_vec	view_dir;
	t_vec	light_dir;
	t_vec	half_dir;
	double	spec_angle;
	double	spec;

	view_dir = v_invert(&ray->direction);
	light_dir = light->isec_point_to_light.direction;
	v_normalize(&view_dir);
	half_dir = v_add(&light_dir, &view_dir);
	v_normalize(&half_dir);
	spec_angle = v_dot(&half_dir, &light->normal);
	spec_angle = spec_angle > 0.0 ? spec_angle : 0.0;
	spec = pow(spec_angle, light->spec_power) * light->intensity;
	return (spec);
}

int			calculate_color(t_rt *rt, t_ray *ray)
{
	t_vec	argb;
	t_vec	out_diff;
	t_vec	out_spec;
	t_light	*tmp_light;

	tmp_light = rt->light_lst;
	if (intersect_objs(rt, ray) == 0)
		return (0);
	argb = v_scale(0.2, &ray->obj->color);
	while (tmp_light != NULL)
	{
		out_diff = v_scale(calculate_diffuse_light(rt, tmp_light, ray),
			&ray->obj->color);
		if (tmp_light->shadow_isec >= tmp_light->sh_v_len ||
			tmp_light->shadow_isec <= 0)
		{
			argb = v_add(&argb, &out_diff);
			out_spec = v_scale(calculate_spec_light(tmp_light, ray),
				&tmp_light->spec_color);
			argb = v_add(&argb, &out_spec);
		}
		tmp_light = tmp_light->next;
	}
	argb_what(&argb);
	return (((int)argb.x << 16) | ((int)argb.y << 8) | (int)argb.z);
}

void		draw_image(t_rt *rt, t_ray *r)
{
	int		x;
	int		y;
	t_vec	c_dir;

	r->start = rt->cam_pos;
	c_dir = v_sub(&rt->cam_dir, &rt->cam_pos);
	v_normalize(&c_dir);
	y = -1;
	while (++y < rt->h)
	{
		x = -1;
		while (++x < rt->w)
		{
			r->type = "vision";
			r->obj = NULL;
			r->direction = camera_dir(rt, c_dir, x, y);
			rt->img_begin[y * rt->w + x] = calculate_color(rt, r);
		}
	}
	free_lists(rt);
	mlx_put_image_to_window(rt->mlx_p, rt->win_p, rt->img_p, 0, 0);
}
