/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_map_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 16:22:21 by sboudouk          #+#    #+#             */
/*   Updated: 2015/05/18 16:22:21 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdio.h>
#include <string.h>

void	ft_print_fps(t_env *env)
{
	double	frameswag;
	char	*str;
	char	*nb;

	env->old_time = env->a_time;
	env->a_time = SDL_GetTicks();
	frameswag = 1 / ((env->a_time - env->old_time) / 1000.0);
	if (frameswag > 60.0)
		frameswag = 60;
	SDL_RenderPresent(env->img);
	nb = ft_itoa((int)frameswag);
	str = ft_strjoin("Wolf3D FPS Counter:", nb);
	SDL_SetWindowTitle(env->window, str);
	free(nb);
	free(str);
}

int		**random_map(int pos_x, int pos_y)
{
	int	x;
	int	y;
	int	**map;

	srand(time(NULL));
	map = (int**)malloc(sizeof(int*) * 15);
	y = 0;
	x = 0;
	while (y < 16)
	{
		x = 0;
		map[y] = (int*)malloc(sizeof(int) * 15);
		while (x < 16)
		{
			if (((y == 0 || y == 15 - 1 || x == 0 || x == 15 - 1)
					|| rand() % 100 > 70) && !((y == 12 && x == 12)))
				map[y][x] = 1;
			else
				map[y][x] = 0;
			x++;
		}
		y++;
	}
	map[pos_x][pos_y] = 0;
	return (map);
}
