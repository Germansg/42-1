/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 12:17:49 by sboudouk          #+#    #+#             */
/*   Updated: 2015/03/17 12:17:53 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	printshell(void)
{
	ft_putendl("		#        #####      #####  #     #");
	ft_putendl("		#    #  #     #    #     # #     #");
	ft_putendl("		#    #        #    #       #     #");
	ft_putendl("		#    #   #####      #####  #######");
	ft_putendl("		####### #                # #     #");
	ft_putendl("		     #  #          #     # #     #");
	ft_putendl("		     #  #######     #####  #     # ");
}

int		ft_executebin(char **line, char *path, t_env **env)
{
	char	**tab_env;
	pid_t	pid;

	pid = fork();
	tab_env = NULL;
	if (pid < 0)
		return (0);
	if (pid > 0)
		wait(NULL);
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		tab_env = ft_list_to_array(env);
		if (execve(path, line, tab_env) != 0)
		{
			ft_exit(1);
		}
	}
	return (0);
}

int		ft_isbuiltin(char **line, t_env **env)
{
	int		i;

	i = 1;
	if (line == NULL || *line == NULL)
		return (-1);
	if (ft_strcmp(line[0], "exit") == 0)
		ft_exit(3);
	if (ft_strcmp(line[0], "cd") == 0)
		return (ft_cd(line, env));
	if (ft_strcmp(line[0], "env") == 0)
		return (ft_print_env(env));
	if (ft_strncmp(line[0], "setenv", 6) == 0)
		return (ft_add_env(line, env));
	if (ft_strncmp(line[0], "unsetenv", 8) == 0)
	{
		while (line[i])
		{
			ft_del_env(line[i], env);
			i++;
		}
		return (1);
	}
	return (0);
}

int		ft_charocc(char *line, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			j++;
		i++;
	}
	return (j);
}

int		ft_find_node(t_env **env, char *str)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (tmp && tmp->name && (ft_strcmp(tmp->name, str) == 0))
			return (1);
		tmp = tmp->nxt;
	}
	return (0);
}
