/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:16:09 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/13 20:59:12 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_RT_H
# define RAYTRACE_RT_H
# include "minilibx_macos/mlx.h"
# include "lft/libft.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_vec
{
	double		x;
	double		y;
	double		z;
}					t_vec;

typedef struct		s_obj
{
	t_vec			position;
	t_vec			color;
	t_vec			axis;
	double			radius;
	char			*type;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_ray
{
	t_vec			start;
	t_vec			direction;
	char			*type;
	t_obj			*obj;
}					t_ray;

typedef struct		s_light
{
	t_vec			position;
	double			intensity;
	t_vec			spec_color;
	double			spec_power;
	struct s_light	*next;
	t_vec			normal;
	t_ray			isec_point_to_light;
	double			sh_v_len;
	double			shadow_isec;
}					t_light;

typedef struct		s_rt
{
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
	int				w;
	int				h;
	int				*img_begin;
	t_vec			(*norm_func)(t_vec *point, t_ray *r, t_obj *object);
	t_vec			cam_pos;
	t_vec			cam_dir;
	t_light			*light_lst;
	t_obj			*obj_lst;
}					t_rt;

t_vec				v_sub(t_vec *v1, t_vec *v2);
double				v_dot(t_vec *v1, t_vec *v2);
t_vec				v_add(t_vec *v1, t_vec *v2);
t_vec				v_scale(double c, t_vec *v);
t_vec				v_del(t_vec *v, double t);
void				v_normalize(t_vec *v);
double				v_length(t_vec *v);
t_vec				v_invert(t_vec *v);
t_vec				v_cross(t_vec *v1, t_vec *v2);
double				intersect_objs(t_rt *rt, t_ray *r);
double				intersect_ray_sphere(t_ray *r, t_obj *sphere);
double				intersect_ray_cone(t_ray *r, t_obj *cone);
double				intersect_ray_cylinder(t_ray *r, t_obj *cyl);
double				intersect_ray_plane(t_ray *r, t_obj *plane);
double				t_calc(double discr, double a, double b);
double				calculate_spec_light(t_light *light, t_ray *ray);
double				calculate_diffuse_light
	(t_rt *rt, t_light *light, t_ray *ray);
void				draw_image(t_rt *rt, t_ray *r);
void				argb_what(t_vec	*argb);
int					ft_close(void *param);
int					keyboard(int key, t_rt *rt);
int					calculate_color(t_rt *rt, t_ray *ray);
t_vec				sphere_normal(t_vec *point, t_ray *r, t_obj *sphere);
t_vec				plane_normal(t_vec *point, t_ray *r, t_obj *plane);
t_vec				cylinder_normal(t_vec *point, t_ray *r, t_obj *cyl);
t_vec				cone_normal(t_vec *point, t_ray *r, t_obj *cone);
void				read_values(t_rt *rt, int fd);
void				free_lists(t_rt *rt);
void				read_spheres(t_rt *rt, char *str);
void				read_planes(t_rt *rt, char *str);
void				read_cylinders(t_rt *rt, char *str);
void				read_cones(t_rt *rt, char *str);
void				read_lights(t_rt *rt, char *str);
void				read_camera(t_rt *rt, char *str);
void				read_sp_input(t_obj *sp, char *str, t_rt *rt);
void				read_pl_input(t_obj *plane, char *str, t_rt *rt);
void				read_cyl_input(t_obj *cyl, char *str, t_rt *rt);
void				read_cone_input(t_obj *cone, char *str, t_rt *rt);
void				read_light_input(t_light *light, char *str, t_rt *rt);
void				free_splitted_str(char **str_arr);
t_vec				camera_dir(t_rt *rt, t_vec dir, int x, int y);
void				quit(char *str, t_rt *rt);
t_vec				v_check(char **str, t_rt *rt);
double				check_value(char *str, t_rt *rt);
void				check_data(char **str, t_rt *rt);
void				check_file(const char *str);

#endif
