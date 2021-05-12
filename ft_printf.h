#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
char	*st_strchr(const char *str, int chr);
char	*st_strnchr(const char *str, int chr, char *end);
size_t	st_put_before_per(const char *format, char *judge_percent);
char	*ft_set_str(va_list ap, char *specifier);
char	*st_itoa_di(va_list ap);
char	*st_itoa_u(va_list ap);
unsigned char	*st_putchr(va_list ap);
char	*st_putstr(va_list ap);
int		ft_count_digits(int n);
char	*ft_malloc(int n);
char	*st_strstr(const char *str, const char *to_find);
char	*ft_strdup(char *src);
size_t	ft_strlen(char *s);
int	ft_atoi(char *str);
char	*st_set_0(char *sentence, char *specifier, char *period);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdog(char *s1, char *s2, char *box);
char	*st_make_width(char *specifier, char *period);
char	*st_cut_sentence(char *sentence, char *specifier, char *period);
char	*st_set_leftspace(char *sentence, char *specifier, char *period);
char	*st_set_x(va_list ap);
char	*st_set_X(va_list ap);
char	*st_set_p(va_list ap);
int	st_count_sixteen(unsigned int num);
char	*st_set_rightspace(char *sentence, char *specifier, char *period);

#endif