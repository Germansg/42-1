/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 10:21:14 by sboudouk          #+#    #+#             */
/*   Updated: 2015/06/04 10:21:14 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Changer le signal du client pour le ctrl-C, envoyer un exit au serv.

#include <ft_p.h>

void	usage(char *str)
{
	printf("Usage: %s <addr> <port number>\n", str);
	exit(-1);
}

int		init_client(char *addr, int port)
{
	int 				sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	connect(sock, (const struct sockaddr*)&sin, sizeof(sin));
	return(sock);
}

void	treatement(int port)
{
	char 		*line;
	char		buf[2000];
	int 		ret;

	write(1, "\x1b[32m\n>>>> \x1b[0m", 15);
	while (get_next_line(0, &line))
	{
		line = ft_strtrim(line);
		if (ft_strlen(line) > 0)
		{
			write(port, line, ft_strlen(line));
			ret = 0;
			while((ret = read(port, buf, 1999)))
			{
				buf[ret] = '\0';
				if (ret > 0)
					printf("%s", buf);
				if (ft_strstr(buf, END_FLAG) || ft_strstr(buf, END_ERR_FLAG))
					break ;
			}
		}
		write(1, "\x1b[32m\n>>>> \x1b[0m", 15);
	}
}

int		main(int ac, char **av)
{
	int 	sock;

	if (ac != 3)
		usage(av[0]);
	sock = init_client(av[1], ft_atoi(av[2]));
	treatement(sock);
	close(sock);
	return (0);
}
