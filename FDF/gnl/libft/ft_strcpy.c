/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:08:09 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/05 17:48:16 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char		*p_dest;
	const char	*p_src = src;

	p_dest = dest;
	while ((*p_dest++ = *p_src++))
		;
	*p_dest = '\0';
	return (dest);
}
