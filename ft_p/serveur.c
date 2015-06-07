/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 10:21:22 by sboudouk          #+#    #+#             */
/*   Updated: 2015/06/04 10:21:22 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

void	usage(char *str)
{
	printf("Usage: %s <port number>\n", str);
	exit(-1);
}

int		init_serv(int port)
{
	int 				sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(sock, (const struct sockaddr*)&sin, sizeof(sin));
	listen(sock, 42);
	return(sock);
}

void	exec_cmd(char **line, int fd2client, int i)  //Utiliser mktemp pour ecrire dans un fichier, et lire dessus !
{
	int 	pid;

	pid = fork();
	if (pid == 0)
	{
		if (gg_tab[i + 1])
		{
			printf("REKKKONNN [%s] %d\n", gg_tab[i + 1], fd2client);
			dup2(fd2client, 1);
			dup2(fd2client, 2);
			execv(gg_tab[i + 1], line);
		}
		else
			return ;
	}
	else
	{
		wait(NULL);
		write(fd2client, "REKT\n", 5);
	}
}

void	ft_check_entry(int fd2client, int port)
{
	int 	i;
	int 	rekt;
	//char	*trimed;
	char 	**tab;
	char	line[250002];

	(void)port;
	while ((rekt = read(fd2client, line, 250001))) //J'ai qu'un appel qui passe, chelou
	{
		line[rekt] = '\0';
		if (ft_strlen(line) > 0)
		{
			printf("ap = [%s]\n", line);
			//strimed = ft_strtrim(line);
			tab = ft_strsplit(line, ' ');
			ft_putstr("printing tab=\n");
			ft_print_tab(tab);
			i = 0;
			while (gg_tab[i])
			{
				if (ft_strcmp(gg_tab[i], tab[0]) == 0)
					exec_cmd(tab, fd2client, i);
				i++;
			}
		}
		printf("in GNL\n");
	}
}

void	treatment(int fd2client, int port)
{
		ft_check_entry(fd2client, port);
}

void	serv_action(int port)
{
	int 				ret;
	int 				pid;
	unsigned int		cslen;
	struct sockaddr_in	csin;

	while (42)
	{
		if ((ret = accept(port, (struct sockaddr*)&csin, &cslen)) > 0)
		{
			pid = fork();
			if (pid == 0)
				treatment(ret, port);
		}
		printf("I BOUKLEUH\n");
	}
	// printf("HELOW\n");
	// ret = accept(port, (struct sockaddr*)&csin, &cslen);
	// write(ret, "coucou!\n", 8);
}

int		main(int ac, char **av)
{
	int		port;

	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	port = init_serv(port);
	serv_action(port);
	close(port);
	return (0);
}
