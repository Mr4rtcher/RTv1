/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:15:52 by jabilbo           #+#    #+#             */
/*   Updated: 2020/11/12 06:26:57 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	check_value(char *str, t_rt *rt)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '.' || ft_isdigit(str[i]))
			i++;
		else
			quit("object value is invalid, please check your data\n", rt);
	}
	return (ft_atof(str));
}

void	quit(char *str, t_rt *rt)
{
	ft_putstr(str);
	mlx_destroy_window(rt->mlx_p, rt->win_p);
	exit(0);
}

void	check_data(char **str, t_rt *rt)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (ft_strnequ(str[0], "camera:", 7) && i == 3)
		return ;
	else if (ft_strnequ(str[0], "sphere:", 7) && i == 4)
		return ;
	else if (ft_strnequ(str[0], "plane:", 6) && i == 4)
		return ;
	else if (ft_strnequ(str[0], "cylinder:", 9) && i == 5)
		return ;
	else if (ft_strnequ(str[0], "cone:", 5) && i == 5)
		return ;
	else if (ft_strnequ(str[0], "light:", 6) && i == 5)
		return ;
	else
		quit("invalid object argument count\n", rt);
}

t_vec	v_check(char **str, t_rt *rt)
{
	t_vec	out;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (i != 3)
		quit("invalid vector argument count\n", rt);
	out.x = check_value(str[0], rt);
	out.y = check_value(str[1], rt);
	out.z = check_value(str[2], rt);
	return (out);
}

void	check_file(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if ((i < 3) ||
	(str[i - 1] != 'c' && str[i - 2] != 's' && str[i - 3] != '.'))
	{
		ft_putstr("invalid file type\n");
		exit(0);
	}
}
