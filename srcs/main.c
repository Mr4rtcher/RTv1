/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:02:42 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/03 01:31:45 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
/*
    http://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm
    a   = D|D - (D|V)^2
    b/2 = D|X - (D|V)*(X|V)
    c   = X|X - (X|V)^2 - r*r
*/

t_vector v_Sub(t_vector *v1, t_vector *v2)
{
	t_vector result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return result;
}

double v_Dot(t_vector *v1, t_vector *v2)
{
	double result;

	result = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (result);
}

t_vector v_Add(t_vector *v1, t_vector *v2)
{
	t_vector result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return result;
}

t_vector v_Mag(t_vector *v, double t)
{
	t_vector f;
	f.x = v->x * t;
	f.z = v->y * t;
	f.z = v->z * t;
	return f;
}

t_vector v_Del(t_vector *v, double t)
{
	t_vector f;
	f.x = v->x / t;
	f.y = v->y / t;
	f.z = v->z / t;
	return f;
}

// double			cilindr_stack(t_data *data)
// {
// 	double		A;
// 	double		B;
// 	double		C;
// 	double		discr;
// 	t_vector	OC, D, V, CV;
// 	double		t1, t2, t;

// 	CV = v_Sub(&data->cilindr_v, &data->cilindr_c);
// 	OC = v_Sub(&data->cilindr_c, &data->camera);
// 	D = v_Del(&data->vector_pixel, sqrt(v_Dot(&data->vector_pixel, &data->vector_pixel)));
// 	V = v_Del(&CV, sqrt(v_Dot(&CV, &CV)));
// 	A = v_Dot(&D, &D) - pow(v_Dot(&D, &V), 2);
// 	B = 2 * (v_Dot(&D, &OC) - v_Dot(&D, &V) * v_Dot(&OC, &V));
//     C = v_Dot(&OC, &OC) - pow(v_Dot(&OC, &V), 2) - 5 * 5;
// 	discr = B * B - 4 * A * C;
// 	if (discr < 0)
// 		return (0);
// 	t1 = (-B + sqrt(discr)) / (2 * A);
// 	t2 = (-B - sqrt(discr)) / (2 * A);
// 	if (t1 > t2)
// 		t = t2;
// 	else
// 		t = t1;
// 	return t;
// }

double			cilindr_stack(t_data *data)
{
	double		A;
	double		B;
	double		C;
	double		discr;
	t_vector	OC, D, V, CV;
	double		t1, t2, t;

	CV = v_Sub(&data->cilindr_v, &data->cilindr_c);
	OC = v_Sub(&data->cilindr_c, &data->camera);
	D = v_Del(&data->vector_pixel, sqrt(v_Dot(&data->vector_pixel, &data->vector_pixel)));
	V = v_Del(&CV, sqrt(v_Dot(&CV, &CV)));
	A = v_Dot(&D, &D) - pow(v_Dot(&D, &V), 2);
	B = 2 * (v_Dot(&D, &OC) - v_Dot(&D, &V) * v_Dot(&OC, &V));
    C = v_Dot(&OC, &OC) - pow(v_Dot(&OC, &V), 2) - 5 * 5;
	discr = B * B - 4 * A * C;
	if (discr < 0)
		return (0);
	t1 = (-B + sqrt(discr)) / (2 * A);
	t2 = (-B - sqrt(discr)) / (2 * A);
	if (t1 > t2)
		t = t2;
	else
		t = t1;
	return t;
}

// V / sqrt (V | V)

int				color(t_data *data)
{
	int			color;

	if (cilindr_stack(data) >= 0){
		color = 0x000000;	
	}
	else
	{
		color = 0xFFFFFF;
	}
	
	return color;
}

int				main(void)
{
	t_data		*data;

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data)))){
		return (1);
	}
	data->mlx_ptr = mlx_init();
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "RTV1"))){
		return (2);
	}

	int			x, y;
	y = 0;
	
	data->camera.x = 0;
	data->camera.y = 0;
	data->camera.z = 0;

	data->cilindr_c.x = 5;
	data->cilindr_c.y = 5;
	data->cilindr_c.z = 100;

	data->cilindr_v.x = 50;
	data->cilindr_v.y = 5;
	data->cilindr_v.z = 110;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			data->vector_pixel.x = ((double)x / (double)1000) - 0.5;
			data->vector_pixel.y = ((double)y / (double)1000) - 0.5;
			data->vector_pixel.z = 1;
			
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color(data));
			x++;
		}
		y++;
	}
	
	mlx_loop(data->mlx_ptr);
	return (0);
}