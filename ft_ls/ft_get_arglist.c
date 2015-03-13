/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arglist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 19:05:27 by sboudouk          #+#    #+#             */
/*   Updated: 2014/12/16 19:05:28 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_err	*ft_yoloerrors(t_err *tmp, t_err *tmp2, t_err *node_err, t_err **error)
{
	node_err->nxt = tmp;
	if (tmp2)
		tmp2->nxt = node_err;
	else
		return (node_err);
	return (*error);
}

t_err	*ft_fillerror(char *name, t_err **error)
{
	t_err	*node_err;
	t_err	*tmp;
	t_err	*tmp2;

	tmp2 = NULL;
	tmp = *error;
	if (!(node_err = (t_err*)malloc(sizeof(t_err))))
		print_err(1, '-');
	node_err->err_name = ft_strdup(name);
	while (tmp)
	{
		if (ft_strcmp(tmp->err_name, node_err->err_name) > 0)
			return (ft_yoloerrors(tmp, tmp2, node_err, error));
		tmp2 = tmp;
		tmp = tmp->nxt;
	}
	if (tmp2)
		tmp2->nxt = node_err;
	else
		return (node_err);
	node_err->nxt = NULL;
	return (*error);
}

int		typedefineargs(int n)
{
	int		i;

	i = 0;
	i = (S_ISBLK(n)) ? 1 : i;
	i = (S_ISCHR(n)) ? 2 : i;
	i = (S_ISDIR(n)) ? 3 : i;
	i = (S_ISFIFO(n)) ? 4 : i;
	i = (S_ISLNK(n)) ? 5 : i;
	i = (S_ISREG(n)) ? 6 : i;
	i = (S_ISSOCK(n)) ? 7 : i;
	return (i);
}

t_infos	*ft_arglentry(t_infos *llist, t_opt *option, char *name, t_err **error)
{
	t_infos		*node;
	struct stat lsts;
	struct stat sts;

	if (!(node = (t_infos*)malloc(sizeof(t_infos))))
		print_err(1, '-');
	node->name = ft_strdup(name);
	if (lstat(node->name, &lsts) == -1)
	{
		*error = ft_fillerror(name, error);
		free(node);
		return (llist);
	}
	node->path = ft_strdup(name);
	node->type = typedefineargs(lsts.st_mode);
	if (option->flag & FLAG_L)
		ft_fillstats(node, &lsts, option);
	else if (node->type == 5)
		if (stat(node->path, &sts) != -1)
			node->type = typedefineargs(sts.st_mode);
	llist = (!llist) ? node : ft_sort(llist, node, option->flag);
	return (llist);
}

t_infos *get_arglist(t_opt *option, t_err **error, char **tab)
{
	t_infos		*llist;

	while (*tab)
	{
		llist = ft_arglentry(llist, option, *tab, error);
		tab++;
	}
	return (llist);
}
