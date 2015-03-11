/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 20:41:12 by sboudouk          #+#    #+#             */
/*   Updated: 2015/01/26 20:41:12 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_px(t_env *e, int y, int x)
{
	if ((x > 0 && y > 0) && (x <= 1280 && y <= 720))
	{
		e->data[(x * 4) + (y * 1280 * 4)] = e->r;
		e->data[(x * 4) + (y * 1280 * 4) + 1] = e->g;
		e->data[(x * 4) + (y * 1280 * 4) + 2] = e->b;
	}
}

void	ft_draw_lines(t_env *e)
{
	double dx;
	double dy;
	double x;
	double y;
	double temp;

	x = e->x1;
	y = e->y1;
	dx = e->x2 - e->x1;
	dy = e->y2 - e->y1;
	temp = sqrt((dx * dx) + (dy * dy));
	dx /= temp;
	dy /= temp;
	while (temp >= 0)
	{
		ft_put_px(e, y, x);
		x += dx;
		y += dy;
		temp--;
	}
}

void	ft_translate(t_env *e, int x, int y, int n)
{
	int		xt;
	int		yt;

	xt = x - e->max_x / 2;
	yt = y - e->max_y / 2;
	e->x1 = 0.40 * (xt - yt) * e->zoom;
	e->y1 = 0.20 * (xt + yt) * e->zoom;
	e->y1 -= e->map[y][x] * e->z_ch;
	if (n)
	{
		e->x2 = 0.40 * ((xt + 1) - yt) * e->zoom;
		e->y2 = 0.20 * ((xt + 1) + yt) * e->zoom;
		e->y2 -= e->map[y][x + 1] * e->z_ch;
	}
	else
	{
		e->x2 = 0.40 * (xt - (yt + 1)) * e->zoom;
		e->y2 = 0.20 * (xt + (yt + 1)) * e->zoom;
		e->y2 -= e->map[y + 1][x] * e->z_ch;
	}
	e->x1 += 1280 / 2;
	e->x2 += 1280 / 2;
	e->y1 += 720 / 2;
	e->y2 += 720 / 2;
}

void	ft_create_image(t_env *e, int n)
{
	int		sizeline;
	int		endian;
	int		bpp;

	if (n == 1)
	{
		e->img_ptr = mlx_new_image(e->mlx, 1280, 720);
		e->data = mlx_get_data_addr(e->img_ptr, &bpp, &sizeline, &endian);
	}
	if (n == 2)
	{
		// mlx_string_put (e->mlx, e->window, 1, 15, 0x66FF66, "Login: sboudouk");
		// mlx_string_put (e->mlx, e->window, 1, 30, 0x66FF66, "Project: FDF");
		// mlx_string_put (e->mlx, e->window, 1, 45, 0x66FF66,
		// "Key usage: '*' '/' '+' '-' 'R G B' 'C' & Arrow keys");
		mlx_put_image_to_window(e->mlx, e->window, e->img_ptr, 0, 0);
		mlx_destroy_image(e->mlx, e->img_ptr);
	}
}

void	ft_draw(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_create_image(e, 1);
	while (y != e->max_y)
	{
		while (x != e->max_x)
		{
			e->x1 = x;
			e->y1 = y;
			if (x + 1 < e->max_x && e->map[y][x] !=\
				INVALID_Z && e->map[y][x + 1] != INVALID_Z)
				ft_translate(e, x, y, 1), ft_draw_lines(e);
			if (y + 1 < e->max_y && e->map[y][x] != \
				INVALID_Z && e->map[y + 1][x] != INVALID_Z)
				ft_translate(e, x, y, 0), ft_draw_lines(e);
			x++;
		}
		x = 0;
		y++;
	}
		mlx_string_put (e->mlx, e->window, 1, 15, 0x66FF66, "Login: sboudouk");
		mlx_string_put (e->mlx, e->window, 1, 30, 0x66FF66, "Project: FDF");
		mlx_string_put (e->mlx, e->window, 1, 45, 0x66FF66,\
		"Key usage: '*' '/' '+' '-' 'R G B' 'C' & Arrow keys");
	ft_create_image(e, 2);
}
