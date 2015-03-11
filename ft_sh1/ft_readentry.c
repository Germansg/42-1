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

int		ft_readentry(char **line, t_env **env)
{
	if (ft_isbuiltin(line, env) == 0)
		if (ft_isbinary(line, env) == 0)
			if (ft_brutexec(line, env) == 0)
				ft_print_err(line, CMD_NOT_FOUND);
	return (0);
}

int		ft_executebin(char **line, char *path, t_env **env) //execve fork etc
{
	char	**tab_env;
	pid_t	pid;
	int		i;

	i = 0;
	pid = fork();
	tab_env = NULL;
	if (pid < 0)
		printf("ERROR FORK\n");
	if (pid > 0)
		wait(NULL);
	else if (pid == 0)
	{
		i = 0;
		tab_env = ft_list_to_array(env);
		// while (tab_env[i])
		// {
		// 	printf("TAB_ENV[%d] = [%s]\n", i, tab_env[i]);
		// 	i++;
		// }
		printf("PATH EX= [%s]\n", path);
		while (line[i])
		{
			printf("LINE[%d] = [%s]\n", i, line[i]);
			i++;
		}
		if (execve(path, line, tab_env) != 0)
		{
			ft_exit (1);
		}
	}
	return (0);
}

int		ft_isbinary(char **line, t_env **env)
{
	t_env	*tmp;
	char	*bin;
	char	*joined;
	char	**paths;
	int		i;

	i = 0;
	tmp = *env;
	while (tmp)
	{
		if (tmp->name && (ft_strcmp(tmp->name, "PATH") == 0))
			break ;
		tmp = tmp->nxt;
	}
	if (!tmp)
		return (0);
	paths = tmp->var;
	while (paths[i])
	{
		printf("PATH[%d] = [%s]\n", i, paths[i]);
		joined = ft_strjoin(paths[i], "/");
		bin = ft_strjoin(joined, line[0]);
		printf("bin = [%s]\n", bin);
		if (access(bin, F_OK) == 0)
		{
			if (access(bin, X_OK) == 0)
			{
				ft_executebin(line, bin, env);
				return (1);
			}
			else
				break ;
		}
		else
		{
			free(joined);
			i++;
		}
	}
	return (0);
}

int		ft_isbuiltin(char **line, t_env **env)
{
	if (line == NULL || *line == NULL)
		return (-1);
	if (ft_strcmp(line[0], "exit") == 0)
	{
		free(line);
		ft_exit(3);
	}
	if (ft_strcmp(line[0], "cd") == 0)
		return(ft_cd(line, env));
	if (ft_strcmp(line[0], "env") == 0)
		return(ft_print_env(env));
	if (ft_strncmp(line[0], "setenv", 6) == 0)
		return(ft_add_env(line, env));
	if (ft_strncmp(line[0], "unsetenv", 8) == 0)
		return(ft_del_env(line ,env));
	return(0);
}

int		ft_cd(char **line, t_env **env)
{
	char	buf[PATH_MAX];
	t_env 	*tmp_pwd;
	t_env 	*tmp_oldpwd;

	tmp_pwd = *env;
	tmp_oldpwd = *env;
	if (line[1] == NULL || line[1][0] == '~')
	{
		printf("CC DEBUG\n");
		while (tmp_pwd && (ft_strcmp(tmp_pwd->name, "HOME") != 0))
			tmp_pwd = tmp_pwd->nxt;
		if (tmp_pwd && tmp_pwd->var[0])
			chdir(tmp_pwd->var[0]);
	}
	else if (line[1][0] == '-')
	{
		while (tmp_oldpwd && (ft_strcmp(tmp_oldpwd->name, "OLDPWD") != 0))
			tmp_oldpwd = tmp_oldpwd->nxt;
		if (tmp_oldpwd && tmp_oldpwd->var[0])
			chdir(tmp_oldpwd->var[0]);
	}
	else
	{
		tmp_pwd = *env;
		chdir(line[1]);
	}
	getcwd(buf, PATH_MAX);
	printf("CC DEBUG2\n");
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
