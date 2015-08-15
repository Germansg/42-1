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

//Close les process fantome avec les ls -R + Ctrl-C (fermeture brutale du prgrm)
//Faire un nouveau changedir

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

void	exec_cmd(char **line, int fd2client, int i)
{
	int 	pid;
	int		statut;

	pid = fork();
	if (pid == 0)
	{
		if (gg_tab[i + 1])
		{
			printf("\nChemin reconnu = [%s]\n", gg_tab[i + 1]);
			dup2(fd2client, 1);
			dup2(fd2client, 2);
			execv(gg_tab[i + 1], line);
		}
		else
			return;
	}
	else
	{
		if (waitpid(pid, &statut, 0) == -1)
			write(fd2client, END_ERR_FLAG, 51);
		else
			write(fd2client, END_FLAG, 51);
	}
}

void	ft_check_entry(int fd2client, int port)
{
	int 	i;
	int 	rekt;
	char 	**tab;
	char	line[250002];

	(void)port;
	while ((rekt = read(fd2client, line, 250001)))
	{
		line[rekt] = '\0';
		if (rekt > 0)
		{
			printf("> Client[%d] asked for [%s].\n", fd2client, line);
			tab = ft_strsplit(line, ' ');
			i = 0;
			while (gg_tab[i])
			{
				if (ft_strcmp(gg_tab[i], tab[0]) == 0)
					exec_cmd(tab, fd2client, i);
				i++;
			}
		}
	}
	printf("\n> \x1b[31mClient[%d] disconnected !\x1b[0m\n", fd2client);
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
			printf("\n> \x1b[32mClient[%d] connected !\x1b[0m\n\n", ret);
			pid = fork();
			if (pid == 0)
				ft_check_entry(ret, port);
		}
	}
}

int		main(int ac, char **av)
{
	int		port;

	if (ac != 2)
		usage(av[0]);
	port = init_serv(ft_atoi(av[1]));
	serv_action(port);
	close(port);
	return (0);
}
