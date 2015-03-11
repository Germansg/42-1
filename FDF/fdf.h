/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 20:12:51 by sboudouk          #+#    #+#             */
/*   Updated: 2015/01/18 20:13:20 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "gnl/get_next_line.h"
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define INVALID_Z	2000000

typedef struct	s_env{

	void	*mlx;
	void	*window;
	void	*img_ptr;
	char	*data;
	int		max_x;
	int		max_y;
	int		r;
	int		g;
	int		b;
	int		zoom;
	int		z_ch;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		**map;
}				t_env;

/*
** GNL
*/

int				get_next_line(int const fd, char **line);

/*
** DRAW
*/

int				ft_init_mlx(t_env *e);
void			ft_put_px(t_env *e, int y, int x);
void			ft_draw_lines(t_env *e);
void			ft_draw(t_env *e);
int				loop_event(t_env *e);
void			ft_create_image(t_env *e, int n);
void			ft_fillmap(t_env *e, char **split, int *x, int y);

#endif
