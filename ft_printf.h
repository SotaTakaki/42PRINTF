#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
    char    *str;
    const char    *percent;
    const char    *period;
    const char    *specifier;
    int     flag;
    int     sub_flag;
    int     field;
    int     accuracy;
    int     minus;
    int     str_len;
    int     all_len;
}   t_list;

int	ft_printf(const char *format, ...);
void    st_initialize(t_list *info);
void	st_put_before_per(const char *format, t_list *info);
void    st_check_info(const char *percent, t_list *info);
void    st_set_width(t_list *info, va_list *ap);
void	st_put_after_spe(t_list *info);
void    st_make_str(t_list *info, va_list *ap);
char	*st_itoa_di(va_list *ap, t_list *info);
char	*st_itoa_u(va_list *ap);
unsigned char	*st_putchr(va_list *ap);
void    st_putstr(va_list *ap, t_list *info);
char	*st_set_x(va_list *ap);
char	*st_set_xx(va_list *ap);
char	*st_set_p(va_list *ap);
void    st_make_acc_di(t_list *info);
void    st_make_acc_else(t_list *info);
void    st_make_field(t_list *info);
void    st_forget_info(t_list *info);

#endif