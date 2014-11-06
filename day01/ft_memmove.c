/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:05:26 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/06 19:36:25 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;

	temp = malloc(sizeof(char) * (len + 1));
	ft_memcpy(temp, src, len);
	ft_memcpy(dst, temp, len);
	free (temp);
	return (dst);
}
