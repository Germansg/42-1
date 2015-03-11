/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:46:20 by sboudouk          #+#    #+#             */
/*   Updated: 2015/02/03 17:49:53 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init_mlx(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (1);
	e->window = mlx_new_window(e->mlx, 1280, 720, "FDF");
	e->r = 100;
	e->g = 100;
	e->b = 100;
	e->zoom = 10;
	e->z_ch = 1;
	return (0);
}

int		loop_event(t_env *e)
{
	ft_draw(e);
	return (0);
}

void	ft_fillmap(t_env *e, char **split, int *x, int y)
{
	int		j;

	j = 0;
	while (split[j] && *x != e->max_x)
	{
		e->map[y][*x] = ft_atoi(split[j]);
		(*x)++;
		j++;
	}
	while (*x != e->max_x)
	{
		e->map[y][*x] = INVALID_Z;
		(*x)++;
	}
}
