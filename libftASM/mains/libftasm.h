#ifndef LIBFTASM_H
# define LIBFTASM_H

#include <string.h>

int 	ft_isalpha(int c);
int 	ft_isdigit(int c);
int 	ft_isalnum(int c);
int 	ft_isascii(int c);
int 	ft_isprint(int c);
int 	ft_tolower(int c);
int 	ft_toupper(int c);
void 	ft_bzero(char *c, int len);
char 	*ft_strcat(char *s1, char *s2);
int 	ft_strlen(char *str);
void 	*ft_memset(void *b, int c, size_t len);
void 	*ft_memcpy(char *dst, char *src, size_t n);
int 	ft_puts(char *s);
int		ft_cat(int fd);
char	*ft_strdup(char *s);
int		ft_isspace(int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_fputs(char *s, int fd);
int 	ft_fputstr(char *s, int fd);
void	ft_putstr(char *s);

#endif
