/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:25:17 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/05 17:08:47 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const	unsigned char	*str1 = (unsigned char*)s1;
	const	unsigned char	*str2 = (unsigned char*)s2;

	while (n--)
	{
		if (*str1 != *str2)
			return ((*str1 - *str2));
		str1++;
		str2++;
	}
	return (0);
}
