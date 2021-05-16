
#include "ft_printf.h"
int	st_count_sixteen(unsigned int num);

char	*st_set_x(va_list *ap)
{
	unsigned int	num;
	int	digits;
	const char	set[17] = "0123456789abcdef";
	char			*str;

	num = va_arg(*ap, unsigned int);
	digits = st_count_sixteen(num);
	str = (char *)malloc(digits + 1);
	str[digits] = '\0';
	digits--;
	while (num > 16)
	{
		str[digits] = set[num % 16];
		num /= 16;
		digits--;
	}
	str[digits] = set[num];
	return (str);
}
