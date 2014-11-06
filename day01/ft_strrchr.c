/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:56:03 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/06 19:46:11 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	char	*last;

	last = 0;
	while (*s1)
	{
		if (*s1 == (char)c)
			last = (char *)s1;
		s1++;
	}
	if (!(last))
		return ((char *)s1);
	return (last);
}
