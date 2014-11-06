/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:33:12 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/05 13:12:46 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <xlocale.h>
#include "libft.h"

int		main(void)
{
	char	s1[]="abcde";
	char	s2[]="ccccc";
//	int		i;

//	i = 0;
	printf ("Moi %s\nYou %s.\n", ft_strcpy(s1, s2), strcpy(s1, s2));
	return (0);
}
