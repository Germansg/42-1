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

#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		return (1);
	env = (t_env*)malloc(sizeof(t_env));
	env->map = ft_parse_map(argv[1]);
	return(0);
}
