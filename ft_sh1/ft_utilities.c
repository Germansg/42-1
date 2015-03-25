/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 06:07:50 by sboudouk          #+#    #+#             */
/*   Updated: 2015/02/16 06:07:50 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_exit(int n)
{
	exit(n);
}

int		ft_check_setenv_validity(char **line)
{
	int		i;

	i = 0;
	while (line[1][i])
	{
		if (line[1][i] == '=')
			if (line[1][i + 1] == '\0')
				return (1);
		i++;
	}
	return (0);
}

int		ft_brutexec(char **line, t_env **env)
{
	char	**tab_env;
	pid_t	pid;

	if ((access(line[0], F_OK) == 0) && (access(line[0], X_OK) == 0))
		pid = fork();
	else
		return (0);
	if (pid > 0)
		wait(NULL);
	else if (pid == 0)
	{
		tab_env = ft_list_to_array(env);
		if (ft_find_node(env, "PATH") == 0 || access(line[0], X_OK) == 0)
		{
			if (execve(line[0], line, tab_env) == -1)
				ft_print_err(line, CMD_NOT_FOUND);
			ft_exit(1);
		}
	}
	return (1);
}

void	ft_create_env(t_env **llist)
{
	t_env	*home;
	t_env	*pwd;
	char	buf[PATH_MAX];

	getcwd(buf, PATH_MAX);
	home = (t_env *)malloc(sizeof(t_env));
	home->name = ft_strdup("HOME");
	home->var = ft_strsplit(buf, ':');
	*llist = home;
	pwd = (t_env*)malloc(sizeof(t_env));
	pwd->name = ft_strdup("PWD");
	pwd->var = ft_strsplit(buf, ':');
	pwd->nxt = NULL;
	home->nxt = pwd;
}

void	ft_lstpushback(t_env **llist, t_env *node)
{
	t_env *tmp;

	tmp = *llist;
	while (tmp->nxt != NULL)
	{
		tmp = tmp->nxt;
	}
	tmp->nxt = node;
}
