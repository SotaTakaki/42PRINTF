
#include "ft_printf.h"

char	*ft_set_str(va_list ap, char *specifier)
{
	if (*specifier == 'd' || *specifier == 'i')
		return (st_itoa_di(ap));
	else if (*specifier == 'u')
		return(st_itoa_u(ap));
	else if (*specifier == 'c')
		return (st_putchr(ap));
	else if (*specifier == 's')
		return (st_putstr(ap));
	else if (*specifier == 'x')
		return (st_set_x(ap));
	else if (*specifier == 'X')
		return (st_set_X(ap));
	else if (*specifier == 'p')
		return (st_set_p(ap));
}