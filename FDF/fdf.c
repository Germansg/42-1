/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 20:12:38 by sboudouk          #+#    #+#             */
/*   Updated: 2015/01/18 20:12:39 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdlib.h"

int		ft_strlenspace(char *line)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i] + 0) == 1)
		{
			j++;
			while (ft_isdigit(line[i] + 0) == 1)
				i++;
		}
		i++;
	}
	return (j);
}

void	ft_count_max(char *argv, t_env *e)
{
	char	*line;
	int		x;
	int		y;
	int		l;
	int		fd;

	l = 0;
	y = 0;
	x = 0;
	fd = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		l = ft_strlenspace(line);
		if (l > x)
			x = l;
		y++;
		if (line)
			free(line);
	}
	close(fd);
	e->max_x = x;
	e->max_y = y - 1;
}

void	ft_parse(char *argv, t_env *e)
{
	char	*line;
	char	**split;
	int		y;
	int		x;
	int		fd;

	x = 0;
	y = 0;
	split = NULL;
	if (!argv)
		return ;
	fd = open(argv, O_RDONLY);
	e->map = (int**)malloc(sizeof(int*) * e->max_y);
	while (get_next_line(fd, &line) == 1 && y != e->max_y)
	{
		e->map[y] = (int*)malloc(sizeof(int) * e->max_x);
		split = ft_strsplit(line, ' ');
		if (split)
			ft_fillmap(e, split, &x, y);
		x = 0;
		if (split)
			free(split);
		y++;
	}
	close(fd);
}

int		keyrelease(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 98 && e->r + 10 < 255)
		e->r = e->r + 10;
	if (keycode == 103 && e->g + 10 < 255)
		e->g = e->g + 10;
	if (keycode == 114 && e->b + 10 < 255)
		e->b = e->b + 10;
	if (keycode == 119)
	{
		e->r = 255;
		e->g = 255;
		e->b = 255;
	}
	if (keycode == 65451)
		e->zoom = e->zoom + 1;
	if (keycode == 65453 && e->zoom - 1 > 0)
		e->zoom = e->zoom - 1;
	if (keycode == 65450 && e->z_ch + 2 < 15)
		e->z_ch = e->z_ch + 2;
	if (keycode == 65455 && e->z_ch - 2 > -15)
		e->z_ch = e->z_ch - 2;
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*e;

	if (ac == 1)
		return (0);
	e = (t_env *)malloc(sizeof(t_env));
	if (ft_init_mlx(e) == 1)
		return (0);
	ft_count_max(av[1], e);
	ft_parse(av[1], e);
	mlx_hook(e->window, 2, 3, keyrelease, e);
	mlx_loop_hook(e->mlx, &loop_event, e);
	mlx_loop(e->mlx);
	return (0);
}
