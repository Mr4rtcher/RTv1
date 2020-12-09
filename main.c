/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:15:52 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/13 20:58:27 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			ft_close(void *param)
{
	(void)param;
	exit(0);
}

void		free_splitted_str(char **str_arr)
{
	int		i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

void		assign_values(t_rt *rt)
{
	int		bpp;
	int		endian;
	int		w;

	bpp = 24;
	endian = 0;
	w = 800;
	rt->w = w;
	rt->h = 800;
	rt->mlx_p = mlx_init();
	rt->win_p = mlx_new_window(rt->mlx_p, rt->w, rt->h, "RayTracing");
	rt->img_p = mlx_new_image(rt->mlx_p, rt->w, rt->h);
	rt->img_begin =
			(int *)mlx_get_data_addr(rt->img_p, &bpp, &w, &endian);
	rt->light_lst = NULL;
	rt->obj_lst = NULL;
	rt->norm_func = sphere_normal;
}

int			main(int ac, char **av)
{
	t_rt	rt;
	t_ray	r;
	int		fd;

	if (ac != 2)
	{
		ft_putstr("usage: ./RTv1 valid_sample_file\n");
		return (0);
	}
	check_file(av[1]);
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putstr("file open error\n");
		return (0);
	}
	assign_values(&rt);
	read_values(&rt, fd);
	draw_image(&rt, &r);
	mlx_hook(rt.win_p, 2, 1, keyboard, &rt);
	mlx_hook(rt.win_p, 17, 0, ft_close, &rt);
	mlx_loop(rt.mlx_p);
	return (0);
}
