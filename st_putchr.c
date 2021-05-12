
#include "ft_printf.h"

unsigned char	*st_putchr(va_list ap)
{
	unsigned char	cast_c;
	unsigned char	*c;

	cast_c = va_arg(ap, int);
	c = (unsigned char *)malloc(sizeof(unsigned char) * 2);
	if (c == NULL)
		return (NULL);
	c[0] = cast_c;
	c[1] = '\0';
	return (c);
}
