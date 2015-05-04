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

void	handle_moves(t_env *e)
{
	e->movespeed = 0.15;
	e->rotspeed = 0.10;
	
	printf("forward = %d\n", e->key.forward);
	printf("back = %d\n", e->key.back);
	printf("pad_right = %d\n", e->key.pad_right);
	printf("pad_left = %d\n", e->key.pad_left);
	if (e->key.forward)
	{
		if (e->map[(int)(e->player.posx + e->player.dirx * e->movespeed)][(int)(e->player.posy)] == 0)
			e->player.posx += e->player.dirx * e->movespeed;
      	if (e->map[(int)(e->player.posx)][(int)(e->player.posy + e->player.diry * e->movespeed)] == 0)
      		e->player.posy += e->player.diry * e->movespeed;
	}
	if (e->key.back)
	{
		if (e->map[(int)(e->player.posx - e->player.dirx * e->movespeed)][(int)(e->player.posy)] == 0)
			e->player.posx -= e->player.dirx * e->movespeed;
		if (e->map[(int)(e->player.posx)][(int)(e->player.posy - e->player.diry * e->movespeed)] == 0)
			e->player.posy -= e->player.diry * e->movespeed;
    }
    if (e->key.pad_right)
    {
    	e->player.oldirx = e->player.dirx;;
    	e->player.dirx = e->player.dirx * cos(-e->rotspeed) - e->player.diry * sin(-e->rotspeed);
    	e->player.diry = e->player.oldirx * sin(-e->rotspeed) + e->player.diry * cos(-e->rotspeed);
    	e->player.oldplanex = e->player.planex;
    	e->player.planex = e->player.planex * cos(-e->rotspeed) - e->player.planey * sin(-e->rotspeed);
    	e->player.planey = e->player.oldplanex * sin(-e->rotspeed) + e->player.planey * cos(-e->rotspeed);
    }
    if (e->key.pad_left)
    {
    	e->player.oldirx = e->player.dirx;
    	e->player.dirx = e->player.dirx * cos(e->rotspeed) - e->player.diry * sin(e->rotspeed);
    	e->player.diry = e->player.oldirx * sin(e->rotspeed) + e->player.diry * cos(e->rotspeed);
    	e->player.oldplanex = e->player.planex;
    	e->player.planex = e->player.planex * cos(e->rotspeed) - e->player.planey * sin (e->rotspeed);
    	e->player.planey = e->player.oldplanex * sin(e->rotspeed) + e->player.planey * cos(e->rotspeed);
    }
}
