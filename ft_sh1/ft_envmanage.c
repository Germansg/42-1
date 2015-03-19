/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envmanage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 21:33:34 by sboudouk          #+#    #+#             */
/*   Updated: 2015/02/15 21:33:34 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int				ft_print_env(t_env **env)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = *env;
	while (tmp != NULL)
	{
		if (tmp)
			ft_putstr(tmp->name);
		if (tmp && !(ft_strchr(tmp->name, '=')))
			ft_putchar('=');
		if (tmp && tmp->var)
			while (tmp->var[i])
			{
				ft_putstr(tmp->var[i]);
				if (tmp->var[i + 1] != NULL)
					ft_putchar(':');
				i++;
			}
		i = 0;
		ft_putchar('\n');
		tmp = tmp->nxt;
	}
	return (1);
}

static int		ft_replace_env(char **line, t_env **env)
{
	t_env	*tmp;
	char	**tmp_name;

	tmp = *env;
	tmp_name = ft_strsplit(line[1], '=');
	if (!line[1])
		return (1);
	while (tmp)
	{
		if (tmp && tmp->name && tmp->var)
			if (ft_strcmp(tmp_name[0], tmp->name) == 0)
			{
				tmp->var[0] = ft_strdup(tmp_name[1]);
				return (1);
			}
		tmp = tmp->nxt;
	}
	return (0);
}

int				ft_add_env(char **line, t_env **env)
{
	t_env	*tmp;
	char	**sline;
	int		i;

	i = 1;
	if (!line[2] && line[1] && ft_charocc(line[1], '=') == 1)
	{
		if (ft_replace_env(line, env) == 0)
			while (line[i])
			{
				if (ft_strchr(line[i], '='))
				{
					tmp = (t_env*)malloc(sizeof(tmp));
					sline = ft_strsplit(line[i], '=');
					tmp->name = ft_strdup(sline[0]);
					tmp->var = ft_strsplit(sline[1], ':');
					tmp->nxt = NULL;
					ft_lstpushback(env, tmp);
				}
				i++;
			}
	}
	else
		ft_print_err(line, SETENV_INVALID_USAGE);
	return (2);
}

static void		ft_del_node(t_env **env, t_env *to_del, t_env *prev, char *line)
{
	t_env *tmp;

	tmp = to_del;
	if (ft_strcmp(to_del->name, line) == 0)
	{
		if (!prev)
		{
			prev = (*env);
			(*env) = (*env)->nxt;
			free(prev);
		}
		else
		{
			if (prev)
				prev->nxt = tmp->nxt;
			free(to_del);
		}
		prev = NULL;
		to_del = *env;
	}
	return ;
}

int				ft_del_env(char *line, t_env **env)
{
	t_env	*tmp;
	t_env	*tmp2;

	tmp2 = NULL;
	tmp = *env;
	while (tmp)
	{
		ft_del_node(env, tmp, tmp2, line);
		tmp2 = tmp;
		tmp = tmp->nxt;
	}
	return (3);
}
