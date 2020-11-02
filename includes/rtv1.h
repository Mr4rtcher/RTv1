/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:09:31 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/03 00:51:44 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H

# define RTV1_H

# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>

typedef float		t_num;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_vector		camera;
	t_vector		vector_pixel;
	t_vector		cilindr_v;
	t_vector		cilindr_c;
}                   t_data;

#endif