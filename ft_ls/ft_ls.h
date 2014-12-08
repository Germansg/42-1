/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 19:45:54 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/29 19:45:54 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#define FLAG_L	1
#define FLAG_CAP_R	2
#define FLAG_A	4
#define FLAG_T	8
#define FLAG_R	16

typedef struct 		g_test
{
	char	*name;
	char	*next;
	char	*prev;
}					t_test;

#endif