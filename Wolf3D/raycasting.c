/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 16:52:33 by sboudouk          #+#    #+#             */
/*   Updated: 2015/05/02 16:52:34 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	display_calculs_part_3(t_env *e, t_play *p, int i)
{
	if (p->verti_ou_horizon == 0)
		p->longueurmur = fabs((p->mapx - p->rayposx + (1 - p->etapex) / 2)
		/ p->raydirx);
	else
		p->longueurmur = fabs((p->mapy - p->rayposy + (1 - p->etapey) / 2)
		/ p->raydiry);
	p->hauteurmur = abs((int)(e->height / p->longueurmur));
	if (p->verti_ou_horizon)
		p->mapy > e->player.posy ? p_pxl(e, 1, i, p->hauteurmur) :
			p_pxl(e, 2, i, p->hauteurmur);
	else
		p->mapx > e->player.posx ? p_pxl(e, 3, i, p->hauteurmur) :
			p_pxl(e, 4, i, p->hauteurmur);
}

void	display_calculs_part_2(t_env *e, t_play *p, int i)
{
	if (p->raydiry < 0 && (p->etapey = -1))
		p->distmury = (p->rayposy - p->mapy) * p->dist2mury;
	else if (p->raydiry > 0 && (p->etapey = 1))
		p->distmury = (p->mapy + 1.0 - p->rayposy) * p->dist2mury;
	while (p->toucher == 0)
	{
		if (p->distmurx < p->distmury)
		{
			p->distmurx += p->dist2murx;
			p->mapx += p->etapex;
			p->verti_ou_horizon = 0;
		}
		else
		{
			p->distmury += p->dist2mury;
			p->mapy += p->etapey;
			p->verti_ou_horizon = 1;
		}
		if (e->map[p->mapx][p->mapy] > 0)
			p->toucher = 1;
	}
	display_calculs_part_3(e, p, i);
}

void	display_calculs(t_env *e, int i)
{
	t_play	p;

	while (i++ < e->width)
	{
		p.camerax = 2 * i / (double)(e->width) - 1;
		p.rayposx = e->player.posx;
		p.rayposy = e->player.posy;
		p.raydirx = e->player.dirx + e->player.planex * p.camerax;
		p.raydiry = e->player.diry + e->player.planey * p.camerax;
		p.mapx = (int)(p.rayposx);
		p.mapy = (int)(p.rayposy);
		p.dist2murx = sqrt\
		(1 + (p.raydiry * p.raydiry) / (p.raydirx * p.raydirx));
		p.dist2mury = sqrt\
		(1 + (p.raydirx * p.raydirx) / (p.raydiry * p.raydiry));
		p.toucher = 0;
		if (p.raydirx < 0 && (p.etapex = -1))
			p.distmurx = (p.rayposx - p.mapx) * p.dist2murx;
		else if (p.raydirx > 0 && (p.etapex = 1))
			p.distmurx = (p.mapx + 1.0 - p.rayposx) * p.dist2murx;
		display_calculs_part_2(e, &p, i);
	}
}
