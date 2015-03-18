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

	getcwd(buf, PATH_MAX);
	ft_putstr("\x1b[32m~> ");
	ft_putstr(buf);
	ft_putstr(" $>\x1b[0m");
	ft_putstr("");
}

void	ft_print_err(char **line, int n)
{
	if (n == CMD_NOT_FOUND)
	{
		ft_putstr("ft_sh1: ");
		ft_putstr(line[0]);
		ft_putchar(':');
		ft_putendl(" command not found or inexisting file/folder.");
	}
	if (n == CD_NOT_FOUND)
	{
		ft_putstr("ft_sh1: ");
		ft_putstr(line[1]);
		ft_putendl(": no such directory or not available.");
	}
	if (n == SETENV_INVALID_USAGE)
	{
		ft_putstr("ft_sh1: setenv: ");
		ft_putendl("Invalid usage (more than one '=', or arguments != 2)");
	}
}
