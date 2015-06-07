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
	char		buf[200];
	int 		ret;

	while (get_next_line(0, &line) > 0)
	{
		write(port, line, ft_strlen(line));
		printf("APRES APRES\n");
		while((ret = read(port, buf, 199)))
		{
			buf[ret] = '\0';
			if (ret > 0)
			{
				printf("%s", buf);
			}
		}
	}
}

int		main(int ac, char **av)
{
	int		port;
	int 	sock;

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	sock = init_client(av[1], port);
	treatement(sock);
	close(sock);
	return (0);
}
