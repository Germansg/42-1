/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-pach <mde-pach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 11:49:44 by mde-pach          #+#    #+#             */
/*   Updated: 2015/03/23 12:01:31 by mde-pach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void	ft_istest(void)
{
	int		i;
	int	win;
	win = 0;
	i = -128;
	printf("\033[1;33m+-+-+-+-+-+\n|f|t|_|i|s|\n+-+-+-+-+-+\n");
	while (i <= 127)
	{
		printf("\033[1;31m");
		if (isalpha(i) != ft_isalpha(i) && (win |= 1))
			printf("%c ft_isalpha->%d isalpha->%d\n", i, ft_isalpha(i), isalpha(i));
		else if (isalnum(i) != ft_isalnum(i) && (win |= 2))
			printf("%c ft_isalnum->%d isalnum->%d\n", i, ft_isalnum(i), isalnum(i));
		else if (isdigit(i) != ft_isdigit(i) && (win |= 4))
			printf("%c ft_isdigit->%d isdigit->%d\n", i, ft_isdigit(i), isdigit(i));
		else if (isascii(i) != ft_isascii(i) && (win |= 8))
			printf("%c ft_isascii->%d isascii->%d\n", i, ft_isascii(i), isascii(i));
		else if (isprint(i) != ft_isprint(i) && (win |= 16))
			printf("%c ft_isprint->%d isprint->%d\n", i, ft_isprint(i), isprint(i));
		i++;
	}
	if (win == 0)
		printf("\033[1;32mft_is ALL OK\n");
	if (win & 1)
		printf("\033[1;31mft_isalpha->KO");
	if (win & 2)
		printf("\033[1;31mft_isalpha->KO");
	if (win & 4)
		printf("\033[1;31mft_isalpha->KO");
	if (win & 8)
		printf("\033[1;31mft_isalpha->KO");
	if (win & 16)
		printf("\033[1;31mft_isalpha->KO");
	printf("\033[0m---------------------------\n");
}

void	ft_bzero_test()
{
	int		i;
	int		win;
	char	test[] = "12345";
	char	test6[] = "je SUI une pouleOK ASM PoWa";

	i = 0;
	printf("\033[1;33m+-+-+-+-+-+-+-+-+\n|f|t|_|b|z|e|r|o|\n+-+-+-+-+-+-+-+-+\n");
	win = 0;
	ft_bzero(test, 5);
	ft_bzero(test6, 26);
	while (i < 5)
	{
		if (test[i] && (win = 1))
			printf("\033[1;31merror %c pour %d\033[0m\n", test[i], i);
		i++;
	}
	i = 0;
	while (i < 26 )
	{
		if (test6[i] && (win = 2))
			printf("\033[1;31merror %c pour %d\033[0m\n", test6[i], i);
		i++;
	}
	i = 0;
	if (win == 0)
		printf("\033[1;32mft_bzero OK\n");
	if (win & 1)
		printf("\033[1;31mtest ONE KO\n");
	if (win & 2)
		printf("\033[1;31mtest TWO KO\n");
	printf("\033[0m---------------------------\n");
}

void	ft_memset_test()
{
	int		i;
	int		win;
	char	test[] = "12345";
	char	test6[] = "je SUI une pouleOK ASM PoWa";

	i = 0;
	printf("\033[1;33m+-+-+-+-+-+-+-+-+-+\n|f|t|_|m|e|m|s|e|t|\n+-+-+-+-+-+-+-+-+-+\n");
	win = 0;
	ft_memset(test, 'y', 5);
	ft_memset(test6, '>', 26);
	while (i < 5)
	{
		if (test[i] != 'y' && (win = 1))
			printf("\033[1;31merror %c pour %d\033[0m\n", test[i], i);
		i++;
	}
	i = 0;
	while (i < 26 )
	{
		if (test6[i] != '>' && (win = 2))
			printf("\033[1;31merror %c pour %d\033[0m\n", test6[i], i);
		i++;
	}
	i = 0;
	if (win == 0)
		printf("\033[1;32mft_memset OK\n");
	if (win & 1)
		printf("\033[1;31mtest ONE KO\n");
	if (win & 2)
		printf("\033[1;31mtest TWO KO\n");
	printf("\033[0m---------------------------\n");
}

void	ft_memset_cpy()
{
	int		win;
	char	test[] = "qwerr";
	char	test2[] = "12345";
	char	test6[] = "je SUI une pouleOK ASM PoWa";
	char	test7[] = "abcdefghijklmnopqrstuvwxyz ";
	char	test3[] = "asdfghjhkj";
	char	test4[] = "abcdefghijklmnopqrstuvwxyz ";
	char	test8[] = "abcdefghijklmnopqrstuvwxyz ";
	char	test9[] = "asdfghjhkj";

	printf("\033[1;33m+-+-+-+-+-+-+-+-+-+\n|f|t|_|m|e|m|c|p|y|\n+-+-+-+-+-+-+-+-+-+\n");
	win = 0;
	ft_memcpy(test, test2, 5);
	ft_memcpy(test6, test7, 27);
	ft_memcpy(test3, test4, 10);
	ft_memcpy(test8, test9, 26);
	if (strcmp(test, test2) && (win |= 1))
		printf("\033[1;31merror %s pour %s\033[0m\n", test2, test);
	if (strcmp(test6, test7) && (win |= 2))
		printf("\033[1;31merror %s pour %s\033[0m\n", test7, test6);
	if (strcmp(test3, "abcdefghij") && (win |= 4))
		printf("\033[1;31merror %s pour %s\033[0m\n", test3, test4);
	if (strcmp(test8, test9) && (win |= 8))
		printf("\033[1;31merror %s pour %s\033[0m\n", test8, test9);

	if (win == 0)
		printf("\033[1;32mft_memcpy OK\n");
	if (win & 1)
		printf("\033[1;31mtest ONE KO\n");
	if (win & 2)
		printf("\033[1;31mtest TWO KO\n");
	if (win & 4)
		printf("\033[1;31mtest THREE KO\n");
	if (win & 8)
		printf("\033[1;31mtest FOUR KO\n");
	printf("\033[0m---------------------------\n");
}

void	ft_strcat_test()
{
	char	test2[] = "54321";
	char	test3[] = "qwertyyui\0\0\0\0\0\0\0\0\0\0";
	char	test4[] = "qwertyyui\0\0\0\0\0\0\0\0\0\0";
	char	test5[] = "plmokijn\0\0\0\0\0\0\0\0\0\0";
	char	test6[] = "plmokijn\0\0\0\0\0\0\0\0\0\0";
	int		win;

	win = 0;
	printf("\033[1;33m+-+-+-+-+-+-+-+-+-+\n|f|t|_|s|t|r|c|a|t|\n+-+-+-+-+-+-+-+-+-+\n");
	ft_strcat(test3, test2);
	strcat(test4, test2);
	ft_strcat(test5, test2);
	strcat(test6, test2);
	if (strcmp(test3, test4) && (win |= 1))
		printf("\033[1;31mt1 error %s pour %s\033[0m\n", test3, test4);
	if (strcmp(test5, test6) && (win |= 2))
		printf("\033[1;31mt2 error %s pour %s\033[0m\n", test5, test6);
	if (win == 0)
		printf("\033[1;32mft_strcat OK\n");
	if (win & 1)
		printf("\033[1;31m test ONE KO\n");
	if (win & 2)
		printf("\033[1;31m test TWO KO\n");
	printf("\033[0m---------------------------\n");
}

void	ft_to_()
{
	char	test5[] = "je SUI une pouleOK ASM PoWa";
	char	test6[] = "je SUI une pouleOK ASM PoWa";
	int		i;

	i = 0;
	while (test5[i])
	{
		test5[i] = ft_tolower(test5[i]);
		test6[i] = ft_toupper(test6[i]);
		i++;
	}
	printf("\033[1;33m+-+-+-+-+-+-+-+-+-+-+\n|f|t|_|t|o|l|o|w|e|r|\n");
	printf("\033[1;33m|f|t|_|t|o|u|p|p|e|r|\n+-+-+-+-+-+-+-+-+-+-+\n");
	if (strcmp(test5, "je sui une pouleok asm powa"))
		printf("\033[1;31mt1 error tolower %s\033[0m\n", test5);
	else
		printf("\033[1;32mft_tolower OK\n");
	if (strcmp(test6, "JE SUI UNE POULEOK ASM POWA"))
		printf("\033[1;31mt1 error toupper %s\033[0m\n", test6);
	else
		printf("\033[1;32mft_ft_toupper OK\n");
}

void	ft_puts_test()
{
	int		i;
	char	buff[1025];
	char	fd[1024];

	printf("\033[1;33m+-+-+-+-+-+-+-+\n|f|t|_|p|u|t|s|\n+-+-+-+-+-+-+-+\033[0m\n");
	i = ft_puts("%$1231526377()*^(^%&$");
	printf("->ret = %d\n", i);
	i = puts("%$1231526377()*^(^%&$");
	printf("->ret = %d\n", i);
	i = ft_puts("ASPDJAS{FHASIUFHASIUFHASUPDHAPIUSDBHAF-018534698173058");
	printf("->ret = %d\n", i);
	i = puts("ASPDJAS{FHASIUFHASIUFHASUPDHAPIUSDBHAF-018534698173058");
	printf("->ret = %d\n", i);
	i = puts("1");
	printf("->ret = %d\n", i);
	i = ft_puts("1");
	printf("->ret = %d\n", i);
	i = puts("");
	printf("->ret = %d\n", i);
	i = ft_puts("");
	printf("->ret = %d\n", i);
	i = puts(NULL);
	printf("->ret = %d\n", i);
	i = ft_puts(NULL);
	printf("->ret = %d\n", i);

	printf("test de puts_fd, entrez une chaine a afficher\n");
	i = read(0, buff, 1024);
	buff[i] = '\0';
	printf("test de puts_fd, entrez un FD\n");
	read(0, fd, 1024);
	fd[i] = '\0';
	ft_fputs(buff, atoi(fd));

	printf("\033[1;33m+-+-+-+-+-+-+-+-+\n|f|t|_|p|u|t|s|t|r|\n+-+-+-+-+-+-+-+-+\033[0m\n");
	ft_putstr("$1231526377()*^(^&$");
	printf("\n");
	printf("$1231526377()*^(^&$");
	printf("\n");
	ft_putstr("ASPDJAS{FHASIUFHASIUFHASUPDHAPIUSDBHAF-018534698173058");
	printf("\n");
	i = printf("ASPDJAS{FHASIUFHASIUFHASUPDHAPIUSDBHAF-018534698173058");
	printf("\n");
		ft_putstr("1");
	printf("\n");
	i = printf("1");
	printf("\n");
		ft_putstr("");
	printf("\n");
	i = printf("");
	printf("\n");

	printf("test de putstr, entrez une chaine a afficher\n");
	i = read(0, buff, 1024);
	buff[i] = '\0';
	printf("test de putstr_fd, entrez un FD\n");
	i = read(0, fd, 1024);
	fd[i] = '\0';
	ft_fputstr(buff, atoi(fd));
}

void	ft_strlen_test()
{
	int		i;

	printf("\033[1;33m+-+-+-+-+-+-+-+-+-+\n|f|t|_|s|t|r|c|a|t|\n+-+-+-+-+-+-+-+-+-+\n");
	if ((i = ft_strlen("lolntr")) != strlen("lolntr"))
		printf("\033[1;31merror for "" ->[%d]\033[0m ", i);
	else
		printf("\033[1;32mgood\033[0m ");
	if ((i = ft_strlen("qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq")) != strlen("qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"))
		printf("\033[1;31merror for "" ->[%d]\033[0m ", i);
	else
		printf("\033[1;32mgood\033[0m ");
	if ((i = ft_strlen("")) != strlen(""))
		printf("\033[1;31merror for "" ->[%d]\033[0m\n", i);
	else
		printf("\033[1;32mgood\033[0m\n");

}

void	ft_cat_test()
{
	char	buff[1024 + 1];
	int		i;
	int		fd;

	printf("\033[1;33m+-+-+-+-+-+-+\n|f|t|_|c|a|t|\n+-+-+-+-+-+-+\033[0m\n");
	printf("tapez 0 pour test l'entrer standard ou un fichier et exit pour arreter le test\n");
	if ((i = read(0, buff, 1024)))
	{
		buff[i - 1] = '\0';
		if (!strcmp(buff, "0"))
			ft_cat(0);
		else if (!strcmp(buff, "exit"))
			;
		else
		{
			fd = open(buff, O_RDONLY);
			printf("%d\n", fd);
			ft_cat(fd);
		}
	}
}
#include <stdlib.h>
void	ft_strdup_test()
{
	char	*s1;//[] = "lollol";
	char	*s2;

	s1 = malloc(sizeof(char) * 5);
	strcpy(s1, "lolo");
	s2 = ft_strdup(s1);
	printf("\033[1;33m+-+-+-+-+-+-+-+-+-+\n|f|t|_|s|t|r|d|u|p|\n+-+-+-+-+-+-+-+-+-+\n");
	if (strcmp(s2, s1))
		printf("\033[1;31merror\033[0m\n");
	else
		printf("\033[1;32mgood\033[0m\n");
	if (strcmp(ft_strdup("aaaaa"), "aaaaa"))
		printf("\033[1;31merror\033[0m\n");
	else
		printf("\033[1;32mgood\033[0m\n");
}

int		main(void)
{
	ft_istest();
	ft_bzero_test();
	ft_memset_test();
	ft_memset_cpy();
	ft_strcat_test();
	ft_to_();
	ft_puts_test();
	ft_strlen_test();
	ft_cat_test();
	ft_strdup_test();
	return (0);
}
