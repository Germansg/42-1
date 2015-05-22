/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 13:52:33 by sboudouk          #+#    #+#             */
/*   Updated: 2015/05/05 13:54:31 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_free_tab(int **tab, int length)
{
	int		i;

	i = 0;
	if (tab[i])
	{
		while (i < length)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}
