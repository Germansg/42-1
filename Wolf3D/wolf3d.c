/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 17:36:14 by sboudouk          #+#    #+#             */
/*   Updated: 2015/04/29 17:36:14 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		**ft_create_map(void)
{
	int		**map;
	int		x;
	int		y;

	y = 0;
	map = (int**)malloc(sizeof(int*) * 15);
	while (y < 16)
	{
		map[y] = (int*)malloc(sizeof(int) * 15);
		x = 0;
		if (y == 0 || y == 15)
		{
			while (x < 16)
			{
				map[y][x] = 1;
				x++;
			}
		}
		else
		{
			while (x < 16)
			{
				if (x == 0 || x == 15)
					map[y][x] = 1;
				else
					map[y][x] = 0;
				x++;
			}
		}
		y++;
	}
	return(map);
}

void ft_sdl_init(t_env *e)
{
	SDL_Init(SDL_INIT_VIDEO);
	e->window = SDL_CreateWindow("Wold3D",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	800, 600, SDL_WINDOW_RESIZABLE);
	e->img = SDL_CreateRenderer(e->window, 1, SDL_RENDERER_ACCELERATED);
	SDL_ShowCursor(SDL_DISABLE);
	e->width = 800;
	e->height = 600;
	e->player.posx = 1.5;
	e->player.posy = 1.5;
	e->player.dirx = -1;
	e->player.diry = 0;
	e->player.planex = 0;
	e->player.planey = 0.66;
	return ;
}

int 	ft_sdl_keyhook(t_env *env)
{
	while (SDL_PollEvent(&(env->event)))
	{
		if (env->event.type == SDL_KEYDOWN)
			ft_key_is_pushed(env);
		if (env->event.type == SDL_KEYUP)
			return (ft_key_is_released(env));
		if (env->event.type == SDL_WINDOWEVENT)
			ft_win_ev(env);
	}
	return (0);
}

void	ft_main_loop(t_env *env)
{
	while (42)
	{
		if (ft_sdl_keyhook(env) == 1)
			return ;
	}
}

int		main(void)
{
	t_env	*env;
	int		y;
	int		x;

	y = 0;
	x = 0;
	env = (t_env*)malloc(sizeof(t_env));
	env->map = ft_create_map();
	ft_sdl_init(env);
	ft_main_loop(env);
	free(env);
	return(0);
}
