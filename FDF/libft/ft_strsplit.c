/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 23:02:22 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/11 22:53:34 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_count_tok(char const *s, char c)
{
	char const		*p_s = s;
	size_t			counter;

	counter = 0;
	while (*p_s)
	{
		if (*p_s == c)
			p_s++;
		else
		{
			counter++;
			while (*p_s && *p_s != c)
				p_s++;
		}
	}
	return (counter);
}

char			**ft_one(char **tab, char const *s)
{
	tab[0] = ft_strdup((char *)s);
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**big_array;
	size_t		i;
	size_t		nb_tok;
	char const	*tok;
	char const	*tok_next;

	if (!(tok = s))
		return (NULL);
	nb_tok = ft_count_tok(s, c);
	if (!(big_array = ft_memalloc(sizeof(char *) * (nb_tok + 1))))
		return (NULL);
	if (nb_tok == 1)
		return (ft_one(big_array, s));
	i = 0;
	while ((tok_next = ft_strchr(tok, c)))
	{
		if ((tok_next - tok) > 0)
			big_array[i++] = ft_strsub(s, tok - s, tok_next - tok);
		tok = tok_next + 1;
	}
	if ((tok_next = ft_strchr(tok, '\0')) - tok > 0)
		big_array[i++] = ft_strsub(s, tok - s, tok_next - tok);
	return (big_array);
}
