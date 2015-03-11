/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:28:00 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/06 19:51:54 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		len;

	len = ft_strlen(s2);
	if (len == 0)
		return ((char *)s1);
	while (*s1)
		if (ft_memcmp(s1++, s2, len) == 0)
			return ((char *)s1 - 1);
	return (NULL);
}
