#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libfts.h"

void test_isalpha(void)
{
	int c = 0;

	printf("\n\n ==========[is_alpha]==========\n");
	while (c < 127)
	{
		if (ft_isalpha(c))
			printf("'%c' : %d\n", c, ft_isalpha(c));
		c++;
	}
}

void test_isdigit(void)
{
	int c = 0;

	printf("\n\n ==========[is_digit]==========\n");
	while (c < 127)
	{
		if (ft_isdigit(c))
			printf("'%c' : %d\n", c, ft_isdigit(c));
		c++;
	}
}

void test_isalnum(void)
{
	int c = 0;

	printf("\n\n ==========[is_alnum]==========\n");
	while (c < 127)
	{
		if (ft_isalnum(c))
			printf("'%c' : %d\n", c, ft_isalnum(c));
		c++;
	}
}

void test_isascii(void)
{
	int c = 0;

	printf("\n\n ==========[is_ascii]==========\n");
	while (c < 127)
	{
		if (ft_isascii(c))
			printf("'%c' : %d\n", c, ft_isascii(c));
		c++;
	}
}

void test_isprint(void)
{
	int c = 0;

	printf("\n\n ==========[is_print]==========\n");
	while (c < 127)
	{
		if (ft_isprint(c))
			printf("'%c' : %d\n", c, ft_isprint(c));
		c++;
	}
}

void test_tolower(void)
{
	char str[] = "AZazFf01\n";
	char *c;

	printf("\n\n ==========[tolower]==========\n");
	c = str;
	while (*c)
	{
		printf("%c", ft_tolower(*c));
		c++;
	}
}

void test_toupper(void)
{
	char str[] = "AZazFf01\n";
	char *c;

	printf("\n\n ==========[toupper]==========\n");
	c = str;
	while (*c)
	{
		printf("%c", ft_toupper(*c));
		c++;
	}
}

void test_bzero(void)
{
	char t1[] = "SASALUT";
	char t2[] = "";
	char *t3 = "MDR";
	int i;

	printf("\n\n ==========[bzero]==========\n");
	ft_bzero(t1, 2);
	ft_bzero(t2, 1);
	ft_bzero(t3, 0);
	i = 0;
	while (i < 7)
		printf("%c", t1[i++]);
	printf("\n");
	i = 0;
	while (i < 1)
		printf("%c", t2[i++]);
	printf("\n");
	i = 0;
	while (i < 3)
		printf("%c", t3[i++]);
	printf("\n");
}

void test_strcat(void)
{
	char *s1;
	char s2[] = " marche !";
	char *ret;

	s1 = (char*)malloc(sizeof(char) * (20));
	s1[0] = 'C';
	s1[1] = 'a';
	s1[2] = ' ';
	s1[3] = '\0';
	printf("\n\n ==========[strcat]==========\n");
	ret = ft_strcat(s1, s2);
	printf("%s\n", ret);
}

void test_strlen(void)
{
	printf("\n\n ==========[strlen]==========\n");
	printf("%d = %d ?\n", 6, ft_strlen("Coucou"));
	printf("%d = %d ?\n", 4, ft_strlen("test"));
	printf("%d = %d ?\n", 0, ft_strlen(""));
}

void test_memset(void)
{
	char *s;

	s = (char*)malloc(sizeof(char) * (10 + 1));
	s[10] = 0;
	s = ft_memset(s, 'a', 10);
	printf("\n\n ==========[memset]==========\n");
	printf("%s\n", s);
}

void test_memcpy(void)
{
	char s1[] = "KO MEMCPY";
	char s2[] = "OK";
	char *r;

	printf("\n\n ==========[memcpy]==========\n");
	r = ft_memcpy(s1, s2, 2);
	printf("%s\n", r);
}

void test_puts(void)
{
	printf("\n\n ==========[ft_puts]==========\n");
	ft_puts("Salur");
	ft_puts(NULL);
}

int main()
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_tolower();
	test_toupper();
	test_bzero();
	test_strcat();
	test_strlen();
	test_memset();
	test_memcpy();
}
