
#include "ft_printf.h"
int	st_count_sixteen(unsigned int num);

char	*st_set_p(va_list *ap)
{
	unsigned int	num;
	int	digits;
	const char			set[17] = "0123456789abcdef";
	char			*str;

	num = va_arg(*ap, unsigned int);
	digits = st_count_sixteen(num) + 2;
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
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

int	st_count_sixteen(unsigned int num)
{
	int	digits;

	digits = 1;
	while (num > 16)
	{
		num /= 16;
		digits++;
	}
	return (digits);
}
