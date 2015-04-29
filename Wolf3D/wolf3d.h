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

#ifndef
# define WOLF3D_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>

typedef	struct	s_player{

	double	posX;				/* Position du joueur */
	double	posY;
	double	dirX;				/* Direction que prends le joueur */
	double	dirY;
	double	planeX;				/* Plan de camera */
	double	planeY;
}				t_player;

typedef struct	s_env{
	int		**map;
}				t_env;

#endif
