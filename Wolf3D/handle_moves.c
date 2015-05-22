/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 20:46:19 by sboudouk          #+#    #+#             */
/*   Updated: 2015/05/02 20:46:19 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	handle_view_left(t_env *e)
{
	if (e->key.pad_left)
	{
		e->player.oldirx = e->player.dirx;
		e->player.dirx = e->player.dirx * cos(e->rotspeed) -\
		e->player.diry * sin(e->rotspeed);
		e->player.diry = e->player.oldirx * sin(e->rotspeed) +\
		e->player.diry * cos(e->rotspeed);
		e->player.oldplanex = e->player.planex;
		e->player.planex = e->player.planex * cos(e->rotspeed) -\
		e->player.planey * sin (e->rotspeed);
		e->player.planey = e->player.oldplanex * sin(e->rotspeed) +\
		e->player.planey * cos(e->rotspeed);
	}
}

void	handle_view_right(t_env *e)
{
	if (e->key.pad_right)
	{
		e->player.oldirx = e->player.dirx;
		e->player.dirx = e->player.dirx * cos(-e->rotspeed) - \
		e->player.diry * sin(-e->rotspeed);
		e->player.diry = e->player.oldirx * sin(-e->rotspeed) + \
		e->player.diry * cos(-e->rotspeed);
		e->player.oldplanex = e->player.planex;
		e->player.planex = e->player.planex * cos(-e->rotspeed) - \
		e->player.planey * sin(-e->rotspeed);
		e->player.planey = e->player.oldplanex * sin(-e->rotspeed) + \
		e->player.planey * cos(-e->rotspeed);
	}
	handle_view_left(e);
}

void	handle_lateral_moves(t_env *e, int dy, int dx)
{
	if (e->key.right)
	{
		if (e->map[(int)(e->player.posx + (e->player.diry * e->movespeed \
			+ dy))][(int)(e->player.posy)] == 0)
			e->player.posx += e->player.diry * e->movespeed;
		if (e->map[(int)(e->player.posx)][(int)(e->player.posy - \
			(e->player.dirx * e->movespeed + dx))] == 0)
			e->player.posy -= e->player.dirx * e->movespeed;
	}
	if (e->key.left)
	{
		if (e->map[(int)(e->player.posx - \
			(e->player.diry * e->movespeed))][(int)(e->player.posy)] == 0)
			e->player.posx -= e->player.diry * e->movespeed;
		if (e->map[(int)(e->player.posx)][(int)(e->player.posy + \
			(e->player.dirx * e->movespeed))] == 0)
			e->player.posy += e->player.dirx * e->movespeed;
	}
	handle_view_right(e);
}

void	handle_moves_back(t_env *e, int dy, int dx)
{
	if (e->key.back)
	{
		if (e->map[(int)(e->player.posx - (e->player.dirx * e->movespeed) - \
			dx)][(int)(e->player.posy)] == 0)
			e->player.posx -= e->player.dirx * e->movespeed;
		if (e->map[(int)(e->player.posx)][(int)(e->player.posy - \
			(e->player.diry * e->movespeed) - dy)] == 0)
			e->player.posy -= e->player.diry * e->movespeed;
	}
	handle_lateral_moves(e, dx, dy);
}

void	handle_moves(t_env *e)
{
	double		dx;
	double		dy;

	e->movespeed = 0.1;
	e->rotspeed = 0.15;
	dx = (e->player.dirx < 0) ? -0.30 : 0.30;
	dy = (e->player.diry < 0) ? -0.30 : 0.30;
	if (e->key.forward)
	{
		if (e->map[(int)(e->player.posx + \
			(e->player.dirx * e->movespeed) + dx)][(int)(e->player.posy)] == 0)
			e->player.posx += e->player.dirx * e->movespeed;
		if (e->map[(int)(e->player.posx)][(int)(e->player.posy + \
			(e->player.diry * e->movespeed) + dy)] == 0)
			e->player.posy += e->player.diry * e->movespeed;
	}
	handle_moves_back(e, dy, dx);
}
