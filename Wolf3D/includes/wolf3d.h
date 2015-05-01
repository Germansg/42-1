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
	int				**map;
	t_keyboard		key;
	int				width;
	int				height;

}				t_env;

/* sdl_manage.c */

void	ft_key_is_pushed(t_env *env);
int		ft_key_is_released(t_env *env);
int		ft_win_ev(t_env *env);

#endif
