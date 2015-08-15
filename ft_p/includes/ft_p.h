/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 10:22:11 by sboudouk          #+#    #+#             */
/*   Updated: 2015/06/04 10:22:11 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_P_H
# define _FT_P_H

# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <netdb.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>

char *gg_tab[] = {
	"ls",
	"/bin/ls",
	"mkdir",
	"/bin/mkdir",
	"pwd",
	"/bin/pwd"
};

#define END_FLAG "\n\n\x1b[32mEnd of operation. Everything seems OK.\x1b[0m\n\n"
#define END_ERR_FLAG "\n\n\x1b[32mError. Try again.\x1b[0m\n\n"

#endif
