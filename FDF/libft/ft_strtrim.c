/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 20:45:09 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/12 00:05:39 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int		ft_isspace_only(int c)
{
	if (c == ' ' ||\
		c == '\t' ||\
		c == '\n')
		return (1);
	else
		return (0);
}

static int		ft_strisspace(char *s)
{
	size_t			len;

	len = ft_strlen(s);
	while (ft_isspace_only(*s))
	{
		s++;
		len--;
	}
	if (!len)
		return (1);
	else
		return (0);
}

char			*ft_strtrim(char const *s)
{
	char const		*begin_s = s;
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = 0;
	if (!s)
		return (NULL);
	if (ft_strisspace((char*)s))
		return (ft_strdup(""));
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
	{
		start++;
		s++;
	}
	while (*s)
		s++;
	s--;
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
	{
		end++;
		s--;
	}
	return (ft_strsub(begin_s, (unsigned int)start,
	ft_strlen(begin_s) - start - end));
}
