/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 00:06:23 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/27 00:06:24 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int			fd;
	struct stat	*buf;

	buf = malloc(sizeof(struct stat));
	if (argc > 1)
	{
		fd = stat(*argv, buf);
		printf("dev = %d\n", buf->st_dev);
		printf("ino = %d\n", buf->st_ino);
		printf("mode = %d\n", buf->st_mode);
		printf("nlink = %d\n", buf->st_nlink);
		printf("uid = %d\n", buf->st_uid);
		printf("gid = %d\n", buf->st_gid);
		printf("rdev = %d\n", buf->st_rdev);
		printf("size = %d\n", buf->st_size);
		printf("blksize = %d\n", buf->st_blksize);
		printf("blocks = %d\n", buf->st_blocks);
		printf("atime = %d\n", buf->st_atime);
		printf("mtime = %d\n", buf->st_mtime);
		printf("ctime = %d\n", buf->st_ctime);
	}
	else
		printf("Too few args\n");
}
