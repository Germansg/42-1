/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:28:03 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/11 17:13:38 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	if (!s2 && !s2)
		return (0);
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (*ps1)
	{
		if (*ps1 != *ps2)
			return ((*ps1 - *ps2));
		ps1++;
		ps2++;
	}
	if (*ps1 != *ps2)
		return ((*ps1 - *ps2));
	return (0);
}
