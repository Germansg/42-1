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

int		ft_brutexec(char **line, t_env **env)
{
	char	**tab_env;
	pid_t	pid;
	int		i;
	int		ret;

	printf("SLT C BRUTEXEC\n");
	pid = 0;
	i = 0;
	tab_env = NULL;
	ret = 0;
	if ((access(line[0], F_OK) == 0) && (access(line[0], X_OK) == 0))
		pid = fork();
	else
		return (0);
	if (pid < 0)
		printf("ERROR FORK\n");
	if (pid > 0)
	{
		wait(NULL);
	}
	else if (pid == 0)
	{
		while (line[i])
		{
			printf("LINE BRUTEXEC[%d] = [%s]\n", i, line[i]);
			i++;
		}
		i = 0;
		tab_env = ft_list_to_array(env);
		// while (tab_env[i])
	 // 	{
		// 	printf("TAB_ENV IN BRUTEX[%d] = [%s]\n", i, tab_env[i]);
		// 	i++;
		// }
		if (access(line[0], F_OK) == 0)
		{
			if (access(line[0], X_OK) == 0)
			{
				execve(line[0], line, tab_env);
				ft_exit(1);
			}
			else
				return (0);
		}
		else
			return(0);
	}
	return (1);
}

void	ft_create_env(t_env **llist)
{	
	t_env 	*home;
	t_env 	*pwd;
	char	buf[PATH_MAX];

	getcwd(buf, PATH_MAX);
	home = malloc(sizeof(home));
	home->name = ft_strdup("HOME");
	home->var = ft_strsplit(buf, ' ');
	*llist = home;
	pwd = malloc(sizeof(pwd));
	pwd->name = ft_strdup("PWD");
	pwd->var = ft_strsplit(buf, ' ');
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
