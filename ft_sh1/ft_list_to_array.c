/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 00:44:16 by sboudouk          #+#    #+#             */
/*   Updated: 2015/02/24 00:45:07 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		ft_listlength(t_env *env)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (tmp)
	{
		tmp = tmp->nxt;
		i++;
	}
	return (i);
}

char	**ft_list_to_array(t_env **env)
{
	t_env	*tmp;
	char	*name;
	char	*var;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = (char**)malloc(sizeof(char *) * (ft_listlength(*env)) + 1);
	tmp = *env;
	var = NULL;
	while (tmp)
	{
		name = ft_strjoin(tmp->name, "=");
		while (tmp->var[j])
		{
			if (j == 0)
				var = ft_strdup(tmp->var[j]);
			else
			{
				var = ft_strjoin(var, ":");
				var = ft_strjoin(var, tmp->var[j]);
			}
			j++;
		}
		j = 0;
		tab[i] = ft_strjoin(name, var);
		ft_strdel(&name);
		ft_strdel(&var);
		i++;
		tmp = tmp->nxt;
	}
	tab[i] = NULL;
	return (tab);
}
