/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:19:25 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/03 19:26:55 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}
