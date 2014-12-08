/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:50:48 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/28 18:50:49 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	print_err(int n)
{
	if (n == 0)
	{
		ft_putendl("ft_ls: illegal option -- -");
		ft_putendl("usage: ft_ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]");
		exit (-1);
	}
}

static int chk_validarg(char *s)
{
	while (*s)
	{
		if ((*s != 'l') || (*s != 'R') || (*s != 'r') || (*s != 't') || (*s != 'a'))
			print_err(0);
		else if (*s == '-')
			;
		s++;
	}
	return (0);
}

static int	chk_score(char *argv)
{
	int		i;
	int 	x;

	i = 0;
	while (argv[i] == '-')
		i++;
	x = i;
	while (argv[x])
	{
		if (argv[x] == '-')
			print_err(0);
		x++;
	}
	if ((i == 2) && (argv[i] != '\0'))
		print_err(0);
	if (i >= 2)
		return (1);
	return (0);
}

static int	reco_options(char *argv)
{
	int		flag;

	flag = 0;
	if (*argv == '-')
		while (*argv)
		{
			if (chk_score(argv) != 0)
				break;
			if (*argv == 'l')
				flag = flag | FLAG_L;
			if (*argv == 'R')
				flag = flag | FLAG_CAP_R;
			if (*argv == 'a')
				flag = flag | FLAG_A;
			if (*argv == 't')
				flag = flag | FLAG_T;
			if (*argv == 'r')
				flag = flag | FLAG_R;
			argv++;
		}
	return (flag);
}

int chk_options(int argc, char **argv)
{
	int		i;
	int		flag;

	flag = 0;
	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (argv[i][0] == '-')
			{
				if ((chk_score(argv[i]) != 0))
					break;
				if (chk_validarg(argv[1]) != 0)
					print_err(0);
				flag = flag | reco_options(argv[i]);
			}
			i++;
		}
	}
	return (flag);
}
