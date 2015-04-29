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

static int	ft_listlength(t_env *env)
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

static char	*ft_copyenv(char *name, char **tab)
{
	char	*ret;
	char	*nom;
	char	*var;
	int		j;

	j = 0;
	nom = ft_strjoin(name, "=");
	while (tab[j])
	{
		if (j == 0)
			var = ft_strdup(tab[j]);
		else
		{
			var = ft_strjoin(var, ":");
			var = ft_strjoin(var, tab[j]);
		}
		j++;
	}
	ret = ft_strjoin(nom, var);
	ft_strdel(&name);
	ft_strdel(&var);
	if (ret)
		return (ret);
	return (NULL);
}

char		**ft_list_to_array(t_env **env)
{
	t_env	*tmp;
	char	**tab;
	int		i;

	i = 0;
	tab = (char**)malloc(sizeof(char *) * (ft_listlength(*env)) + 1);
	tmp = *env;
	while (tmp)
	{
		if (tmp->name && tmp->var && tmp->var[0])
			tab[i] = ft_copyenv(tmp->name, tmp->var);
		i++;
		tmp = tmp->nxt;
	}
	tab[i] = NULL;
	return (tab);
}
