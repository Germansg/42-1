/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:59:04 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/07 18:24:55 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*nzone;

	if (!size)
		return (NULL);
	nzone = (void *)malloc(sizeof(void*) * size);
	if (!nzone)
		return (NULL);
	ft_bzero(nzone, size);
	return (nzone);
}
