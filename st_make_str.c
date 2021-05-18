#include "ft_printf.h"
void    st_set_str(t_list *info, va_list *ap);

void    st_make_str(t_list *info, va_list *ap)
{
    st_set_str(info, ap);
    if (info->specifier[0] == 'd' || info->specifier[0] == 'i')
	{
		st_make_acc_di(info);
	}
	else if (info->specifier[0] == 's')
	{
		st_make_acc_s(info);
	}
	else
		st_make_acc_else(info);
	st_make_field(info);
	info->all_len += st_strlen(info->str);
	info->str_len = st_strlen(info->str);
	write(1, info->str, info->str_len);
}

void    st_set_str(t_list *info, va_list *ap)
{
	if (*(info->specifier) == 'd' || *(info->specifier) == 'i')
		info->str = st_itoa_di(ap, info);
	else if (*(info->specifier) == 'u')
		info->str = st_itoa_u(ap);
	else if (*(info->specifier) == 'c')
		info->str = (char *)st_putchr(ap);
	else if (*(info->specifier) == 's')
		st_putstr(ap, info);
	else if (*(info->specifier) == 'x')
		info->str = st_set_x(ap);
	else if (*(info->specifier) == 'X')
		info->str = st_set_xx(ap);
	else if (*(info->specifier) == 'p')
		info->str = st_set_p(ap);
}
