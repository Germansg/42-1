/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:28:03 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/11 23:44:42 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	if ((!s1 && !s2) && n > (ft_strlen(s1) + ft_strlen(s2)))
		return (0);
	while (n--)
	{
		if (*s1 != *s2)
			return (*(unsigned char*)(s1) - *(unsigned char*)(s2));
		if (!*s1 || !*s2)
			break ;
		s1++;
		s2++;
	}
	return (0);
}
