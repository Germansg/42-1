/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 19:30:39 by sboudouk          #+#    #+#             */
/*   Updated: 2015/02/14 19:30:39 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include "libft/includes/libft.h"
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/acl.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include <signal.h>

# define CMD_NOT_FOUND			1
# define CD_NOT_FOUND 			2
# define SETENV_INVALID_USAGE	3
# define ENV_NOT_FOUND			4

typedef	struct	s_env
{
	char			*name;
	char			**var;
	struct s_env	*nxt;
}				t_env;

/*
** ft_sh1.c + 1 static, main & ft_sh1.
*/

void			ft_firstclean(char *line, t_env **e);
void			ft_cleanline(char *line, t_env **e);

/*
** ft_readentry.c + 1 static.
*/

int				ft_readentry(char **line, t_env **l_env);
int				ft_cd(char **line, t_env **env);
int				ft_isbuiltin(char **line, t_env **env);
int				ft_isbinary(char **line, t_env **env);

/*
** ft_envmanage.c + 2 static.
*/

int				ft_print_env(t_env **env);
int				ft_add_env(char **line, t_env **env);
int				ft_del_env(char *line, t_env **env);

/*
** ft_errors.c
*/

void			ft_print_err(char **line, int n);
void			ft_prompt(void);

/*
** ft_utilities.c
*/

void			ft_lstpushback(t_env **llist, t_env *node);
int				ft_brutexec(char **line, t_env **env);
void			ft_create_env(t_env **llist);
void			ft_exit(int n);
int				ft_check_setenv_validity(char **line);

/*
** ft_list_to_array.c + 2 static.
*/

char			**ft_list_to_array(t_env **env);

/*
** ft_util2.c
*/

int				ft_executebin(char **line, char *path, t_env **env);
void			printshell(void);
int				ft_find_node(t_env **env, char *str);
int				ft_charocc(char *line, char c);

#endif
