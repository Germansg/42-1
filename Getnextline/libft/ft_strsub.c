/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:51:02 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/12 00:10:15 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*new_str;
	char		*begin_new_str;

	if (!s)
		return (NULL);
	new_str = ft_strnew(len);
	if (new_str == NULL)
		return (NULL);
	begin_new_str = new_str;
	while (start--)
		s++;
	while (*s && len--)
		*new_str++ = *s++;
	return (begin_new_str);
}
