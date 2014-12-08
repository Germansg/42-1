/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 21:07:31 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/26 21:18:32 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_ls.h"

void	readir(DIR *ret)
{
	int				r;
	struct dirent 	*dirp;
	unsigned int	count;

	r = 0;
	count = 0;
	while ((dirp = readdir(ret)) != NULL)
	{
		printf("%s\n", dirp->d_name);
	}
}

int		main(int argc, char **argv)
{
	DIR 			*ret;
	t_test			*lst;
	int				option;
	struct dirent	*files;

	ret = opendir(".");
	lst = (t_test *)malloc(sizeof(t_test));
	option = chk_options(argc, argv);
	files = readdir(ret);
	lst->name = files->d_name;
	ft_putendl(lst->name);
	/*if (argc > 1)
	{
		ret = opendir(argv[1]);
		readir(ret);
	}
	else
	{
		ret = opendir(".");
		readir(ret);
	}*/
	printf ("flag = %d", option);
	return (0);
}
