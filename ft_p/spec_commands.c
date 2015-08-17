/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 18:35:57 by sboudouk          #+#    #+#             */
/*   Updated: 2015/08/17 18:35:57 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

void	ft_manage_chdir(char **tab, int fd2client)
{
	chdir(tab[1]);
	write (fd2client, "CD WORKED.", 10);
}

void	ft_spec_commands(char **tab, int fd2client)
{
	if (ft_strcmp("cd", tab[0]) == 0)
		ft_manage_chdir(tab, fd2client);
	if (ft_strcmp("get", tab[0]) == 0)
		;
	if (ft_strcmp("put", tab[0]) == 0)
		;
}
