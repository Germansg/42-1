/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:32:17 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/11 17:35:35 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new;

	if (!s || !f)
		return (NULL);
	i = 0;
	new = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		new[i] = f((unsigned int)i, s[i]);
		i++;
	}
	return (new);
}
