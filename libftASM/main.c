#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_bzero(void *s, size_t n);

int		main(void)
{
	char	*test;

	test = strdup("yoloswag\n");
	printf("1st = %s\n", test);
	ft_bzero(test, 9);
	printf("2nd = %s\n", test);
	return (0);
}
