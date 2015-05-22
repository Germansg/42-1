/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 17:12:16 by sboudouk          #+#    #+#             */
/*   Updated: 2015/05/21 14:27:10 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	mouse_pos(t_env *env)
{
	int			x;
	int			y;

	SDL_GetRelativeMouseState(&x, &y);
	if (x > 0)
		env->key.pad_right = 1;
	else
		env->key.pad_right = 0;
	if (x < 0)
		env->key.pad_left = 1;
	else
		env->key.pad_left = 0;
}

void	ft_free_struct(t_env *e)
{
	if (e->map)
		ft_free_tab(e->map, 15);
	if (e->img)
		SDL_DestroyRenderer(e->img);
	if (e->window)
		SDL_DestroyWindow(e->window);
	free(e);
}

void	ft_key_is_pushed(t_env *env)
{
	if (env->event.key.keysym.sym == SDLK_a)
		env->key.left = 1;
	if (env->event.key.keysym.sym == SDLK_RIGHT)
		env->key.pad_right = 1;
	if (env->event.key.keysym.sym == SDLK_d)
		env->key.right = 1;
	if (env->event.key.keysym.sym == SDLK_LEFT)
		env->key.pad_left = 1;
	if (env->event.key.keysym.sym == SDLK_w)
		env->key.forward = 1;
	if (env->event.key.keysym.sym == SDLK_UP)
		env->key.forward = 1;
	if (env->event.key.keysym.sym == SDLK_s)
		env->key.back = 1;
	if (env->event.key.keysym.sym == SDLK_DOWN)
		env->key.back = 1;
	if (env->event.key.keysym.sym == SDLK_x)
		env->gen_random_map = 1;
	if (env->event.key.keysym.sym == SDLK_e)
		SDL_SetRelativeMouseMode(1);
	if (env->event.key.keysym.sym == SDLK_r)
		SDL_SetRelativeMouseMode(0);
}

int		ft_key_is_released(t_env *env)
{
	if (env->event.key.keysym.sym == SDLK_ESCAPE)
		return (1);
	if (env->event.key.keysym.sym == SDLK_a)
		env->key.left = 0;
	if (env->event.key.keysym.sym == SDLK_RIGHT)
		env->key.pad_right = 0;
	if (env->event.key.keysym.sym == SDLK_d)
		env->key.right = 0;
	if (env->event.key.keysym.sym == SDLK_LEFT)
		env->key.pad_left = 0;
	if (env->event.key.keysym.sym == SDLK_w)
		env->key.forward = 0;
	if (env->event.key.keysym.sym == SDLK_UP)
		env->key.forward = 0;
	if (env->event.key.keysym.sym == SDLK_s)
		env->key.back = 0;
	if (env->event.key.keysym.sym == SDLK_DOWN)
		env->key.back = 0;
	return (0);
}

int		ft_win_ev(t_env *env)
{
	if (env->event.window.event == SDL_WINDOWEVENT_RESIZED)
		SDL_GetWindowSize(env->window, &env->width, &env->height);
	return (0);
}
