/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:25:51 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/06 19:54:06 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*p_s1;
	const char	*p_s2 = s2;

	p_s1 = s1;
	while (n--)
	{
		*p_s1++ = *p_s2;
		if (*p_s2 == (unsigned char)c)
			return (p_s1);
		p_s2++;
	}
	return (0);
}
