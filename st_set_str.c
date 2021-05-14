
#include "ft_printf.h"

char	*st_set_str(va_list *ap, char *specifier)
{
	char	*str;

	if (*specifier == 'd' || *specifier == 'i')
		str = st_itoa_di(ap);
	else if (*specifier == 'u')
		str = st_itoa_u(ap);
	else if (*specifier == 'c')
		str = (char *)st_putchr(ap);
	else if (*specifier == 's')
		str = st_putstr(ap);
	else if (*specifier == 'x')
		str = st_set_x(ap);
	else if (*specifier == 'X')
		str = st_set_xx(ap);
	else if (*specifier == 'p')
		str = st_set_p(ap);
	//printf("str:%s\n", str);
	return (str);
}

