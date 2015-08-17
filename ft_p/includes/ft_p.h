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

#ifndef _FT_P_H_
# define _FT_P_H_

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
# include <limits.h>

char home_dir[PATH_MAX];

char *gg_tab[] = {
	"ls",
	"/bin/ls",
	"mkdir",
	"/bin/mkdir",
	"pwd",
	"/bin/pwd",
	"not"
};

#define END_FLAG "\n\n\x1b[32mOperation OK.\x1b[0m\n\n"
#define END_ERR_FLAG "\n\n\x1b[31mError. Retry.\x1b[0m\n\n"

// int		ft_spec_commands(char **tab, int fd2client);

#endif
