
#include "ft_printf.h"

char	*st_putstr(va_list ap)
{
	char	*tmp;
	char	*str;

	tmp = va_arg(ap, char*);
	str = ft_strdup(tmp);
	return (str);
}