/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:25:02 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/06 17:09:39 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int		sign;
	int		rslt;

	rslt = 0;
	sign = 0;
	while (ft_isspace(*nptr) && *nptr != '\0')
		nptr++;
	if ((*nptr == '-' || *nptr == '+') && *nptr != '\0')
	{
		if (*nptr == '-')
			sign = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		rslt *= 10;
		rslt += (*nptr - 48);
		nptr++;
	}
	if (sign)
		rslt = -(rslt);
	return (rslt);
}
