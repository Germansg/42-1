/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 19:30:43 by sboudouk          #+#    #+#             */
/*   Updated: 2015/02/14 19:30:43 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Quand je supprime deux node a la suite , SEGV X
*/

#include "ft_sh1.h"

static void	ft_fill_list(t_env **llist, char **env)
{
	t_env	*node;
	t_env	*l_tmp;
	char	**tmp;
	int		i;

	i = 0;
	while (env[i])
	{
		node = (t_env*)malloc(sizeof(node));
		tmp = ft_strsplit(env[i], '=');
		node->name = ft_strdup(tmp[0]);
		node->var = ft_strsplit(tmp[1], ':');
		if (*llist == NULL)
		{
			*llist = node;
			l_tmp = *llist;
		}
		else
		{
			l_tmp->nxt = node;
			l_tmp = l_tmp->nxt;
		}
		i++;
	}
	l_tmp->nxt = NULL;
}

void		ft_firstclean(char *line, t_env **e)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(line, ';');
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		ft_cleanline(tab[i], e);
		i++;
	}
	if (tab)
		free(tab);
}

void		ft_cleanline(char *line, t_env **e)
{
	char	**ret;
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]) == 1)
			line[i] = ' ';
		i++;
	}
	line = ft_strtrim(line);
	ret = ft_strsplit(line, ' ');
	ft_readentry(ret, e);
}

t_env		*ft_sh1(char **env, t_env *e)
{
	char	*line;
	t_env	*l_env;

	l_env = e;
	line = NULL;
	if (env[0] == NULL && l_env == NULL)
		ft_create_env(&l_env);
	else if (l_env == NULL)
		ft_fill_list(&l_env, env);
	ft_prompt();
	if (get_next_line(0, &line) <= 0)
		ft_exit(-1);
	if (line)
		ft_firstclean(line, &l_env);
	return (l_env);
}

int			main(int ac, char **av, char **env)
{
	t_env *e;

	e = NULL;
	signal(SIGINT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	printshell();
	if (ac || av)
		while (42)
			e = ft_sh1(env, e);
	return (0);
}
