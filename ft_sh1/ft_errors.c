/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 01:48:26 by sboudouk          #+#    #+#             */
/*   Updated: 2015/02/26 01:48:28 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_prompt(void)
{
	char	buf[PATH_MAX];
	char	*prompt;

	getcwd(buf, PATH_MAX);
	ft_putstr("\x1b[32m~> ");
	prompt = ft_strrchr(buf, '/');
	ft_putstr("[");
	ft_putstr(prompt);
	ft_putstr("]");
	ft_putstr(" $>\x1b[0m");
	ft_putstr("");
}

void	ft_print_err(char **line, int n)
{
	if (n == CMD_NOT_FOUND)
	{
		ft_putstr_fd("ft_sh1: ", 2);
		if (line[0])
			ft_putstr_fd(line[0], 2);
		ft_putchar_fd(':', 2);
		ft_putendl_fd(" command not found: no such file/folder,or no rights",\
		2);
	}
	if (n == CD_NOT_FOUND)
	{
		ft_putstr_fd("ft_sh1: ", 2);
		if (line[1])
			ft_putstr_fd(line[1], 2);
		ft_putendl_fd(": no such directory or not available.", 2);
	}
	if (n == SETENV_INVALID_USAGE)
		ft_putendl_fd("ft_sh1: setenv: Bad usage: example ('setenv a=b')", 2);
	if (n == ENV_NOT_FOUND)
	{
		ft_putstr_fd("ft_sh1: unsetenv: Bad usage: example 'unsetenv VARNAME'",
		2);
		ft_putendl_fd(" or VARNAME not found on environement.", 2);
	}
}
