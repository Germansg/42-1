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

#include "ft_ls.h"

void	main_display2(t_infos *infos, t_err *error, t_opt *option)
{
	if (option->flag & FLAG_CAP_R)
	{
		if (option->j == 1 && !infos->nxt)
			display_recursive(infos, option, 2, option->j);
		else
			display_recursive(infos, option, option->n, option->j);
	}
	else if (option->j == 1 && infos != NULL)
	{
		if (!infos->nxt && !error)
			displaydirs(infos, option, 2);
		else if (error && !infos->nxt)
			displaydirs(infos, option, 0);
		else
			displaydirs(infos, option, option->n);
	}
	if (option)
		free(option);
	ft_freellist(infos);
}

void	main_display(t_infos *infos, t_err *error, t_opt *option, char **files)
{
	if (error && files)
		display_err(error);
	if (infos != NULL)
	{
		if (option->flag & FLAG_D)
			;
		else
			option->n = display(infos, option, option->j);
	}
	if (option->flag & FLAG_D)
	{
		display(infos, option, 0);
		free(option);
		ft_freellist(infos);
		exit (0);
	}
	ft_ajustmaxsize(option);
	main_display2(infos, error, option);
}

int		main(int argc, char **argv)
{
	char			**files;
	t_infos			*infos;
	t_opt			*option;
	t_err			*error;

	infos = NULL;
	error = NULL;
	if (!(option = (t_opt*)malloc(sizeof(t_opt))))
		print_err(1, '-');
	option->j = 1;
	option->n = 0;
	option->flag = chk_options(argc, argv);
	files = get_files(argc, argv, NULL);
	if (option->flag & FLAG_D && !files)
	{
		option->j = 0;
		files = get_files(1, NULL, ".");
		infos = get_arglist(option, &error, files);
	}
	else if (!files || files[0] == '\0')
		infos = ft_listdir(".", ".", option);
	else
		infos = get_arglist(option, &error, files);
	main_display(infos, error, option, files);
	return (0);
}
