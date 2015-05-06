/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 17:36:23 by sboudouk          #+#    #+#             */
/*   Updated: 2015/04/29 17:40:05 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <SDL.h>

typedef struct 		s_play{

	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			distmurx;
	double			distmury;
	double			dist2murx;
	double			dist2mury;
	double			longueurmur;
	int				hauteurmur;
	int				toucher;
	int				verti_ou_horizon;
	int				etapex;
	int				etapey;
	int				drawstart;
	int				drawend;
	int				mapx;
	int				mapy;

}					t_play;

typedef struct 		s_keyboard{

	int				pad_left;
	int				pad_right;
	int				forward;
	int				back;
	int				left;
	int				right;
	int				up;
	int				hud;
	int				down;

}					t_keyboard;

typedef	struct		s_player{

	double	oldirx;
	double	oldiry;
	double	oldplanex;
	double	oldplaney;
	double	posx;				/* Position du joueur */
	double	posy;
	double	dirx;				/* Direction que prends le joueur */
	double	diry;
	double	planex;				/* Plan de camera */
	double	planey;
}					t_player;

typedef struct	s_env{

	SDL_Window		*window;
	SDL_Event		event;
	SDL_Renderer	*img;
	SDL_Surface		*surface;
	t_player		player;
	double			time;
	double			oldtime;
	double			movespeed;
	double			rotspeed;
	double			a_time;
	double			old_time;
	int				**map;
	t_keyboard		key;
	int				width;
	int				height;

}				t_env;

/* sdl_manage.c */


void	ft_free_struct(t_env *e);
void	handle_moves(t_env *e);
void	p_pxl(t_env *e, double cl, int x, int h);
void	ft_key_is_pushed(t_env *env);
int		ft_key_is_released(t_env *env);
int		ft_win_ev(t_env *env);
void	display_calculs(t_env *e, int i);

#endif
