/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readentry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 21:24:22 by sboudouk          #+#    #+#             */
/*   Updated: 2015/02/15 21:24:23 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int				ft_readentry(char **line, t_env **env)
{
	if (ft_isbuiltin(line, env) == 0)
		if (ft_isbinary(line, env) == 0)
			if (ft_brutexec(line, env) == 0)
				ft_print_err(line, CMD_NOT_FOUND);
	return (0);
}

char			**ft_found_path(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (tmp->name && (ft_strcmp(tmp->name, "PATH") == 0))
			break ;
		tmp = tmp->nxt;
	}
	if (!tmp)
		return (NULL);
	else
		return (tmp->var);
}

int				ft_isbinary(char **line, t_env **env)
{
	char	*bin;
	char	*joined;
	char	**paths;
	int		i;

	i = 0;
	if (!(paths = ft_found_path(env)))
		return (0);
	while (paths[i])
	{
		joined = ft_strjoin(paths[i], "/");
		bin = ft_strjoin(joined, line[0]);
		if (access(bin, F_OK) == 0)
		{
			if (access(bin, X_OK) == 0)
			{
				ft_executebin(line, bin, env);
				return (1);
			}
		}
		else
			free(joined);
		i++;
	}
	return (0);
}

static int		ft_movedir(char **line, t_env **env)
{
	t_env	*tmp_pwd;
	t_env	*tmp_oldpwd;

	tmp_pwd = *env;
	tmp_oldpwd = *env;
	if (line[1] == NULL || line[1][0] == '~')
	{
		while (tmp_pwd && (ft_strcmp(tmp_pwd->name, "HOME") != 0))
			tmp_pwd = tmp_pwd->nxt;
		if (tmp_pwd && tmp_pwd->var[0])
			return (chdir(tmp_pwd->var[0]));
	}
	else if (line[1][0] == '-')
	{
		while (tmp_oldpwd && (ft_strcmp(tmp_oldpwd->name, "OLDPWD") != 0))
			tmp_oldpwd = tmp_oldpwd->nxt;
		if (tmp_oldpwd && tmp_oldpwd->var[0])
			return (chdir(tmp_oldpwd->var[0]));
	}
	else
	{
		tmp_pwd = *env;
		return (chdir(line[1]));
	}
	return (-1);
}

int				ft_cd(char **line, t_env **env)
{
	char	buf[PATH_MAX];
	t_env	*tmp_pwd;
	t_env	*tmp_oldpwd;

	tmp_pwd = *env;
	tmp_oldpwd = *env;
	if (ft_movedir(line, env) == -1)
	{
		ft_print_err(line, CD_NOT_FOUND);
		return (3);
	}
	getcwd(buf, PATH_MAX);
	while (tmp_pwd && (ft_strcmp(tmp_pwd->name, "PWD") != 0))
		tmp_pwd = tmp_pwd->nxt;
	while (tmp_oldpwd && (ft_strcmp(tmp_oldpwd->name, "OLDPWD") != 0))
		tmp_oldpwd = tmp_oldpwd->nxt;
	if ((tmp_pwd && tmp_oldpwd) && (tmp_oldpwd->var[0] && tmp_pwd->var[0]))
	{
		tmp_oldpwd->var[0] = ft_strdup(tmp_pwd->var[0]);
		tmp_pwd->var[0] = ft_strdup(buf);
	}
	return (3);
}
