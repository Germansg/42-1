/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 20:46:19 by sboudouk          #+#    #+#             */
/*   Updated: 2015/05/02 20:46:19 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	p_pxl(t_env *e, double cl, int x, int h)
{
	int	start;
	int	i;

	i = 0;
	start = e->height / 2 - h / 2;
	SDL_SetRenderDrawColor(e->img, 0, 128, 255, 255);
	while (i < start)
	{
		SDL_RenderDrawPoint(e->img, x, i);
		++i;
	}
	i = 0;
	if (cl == 1)
		SDL_SetRenderDrawColor(e->img, 255, 153, 151, 255);
	else if (cl == 2)
		SDL_SetRenderDrawColor(e->img, 255, 51, 51, 255);
	else if (cl == 3)
		SDL_SetRenderDrawColor(e->img, 255, 255, 51, 255);
	else
		SDL_SetRenderDrawColor(e->img, 128, 255, 0, 255);
	while (i < h)
	{
		SDL_RenderDrawPoint(e->img, x, start);
		++i;
		++start;
	}
	SDL_SetRenderDrawColor(e->img, 192, 192, 192, 255);
	while (start < e->height)
	{
		SDL_RenderDrawPoint(e->img, x, start);
		++start;
	}
}
