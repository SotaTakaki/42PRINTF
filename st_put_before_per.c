
#include "ft_printf.h"

size_t	st_put_before_per(const char *start, char *percent)
{
	size_t	len;

	len = percent - start;
	write(1, start, len);
	return (len);	
}