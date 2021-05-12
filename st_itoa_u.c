
#include "ft_printf.h"

char	*st_itoa_u(va_list ap)
{
	unsigned int	n;
	int				digits;
	char			*arg_n;

	n = va_arg(ap, unsigned int);
	digits = ft_count_digits(n) - 1;
	arg_n = ft_malloc(n);
	if (arg_n == NULL)
		return (NULL);
	while (n >= 10)
	{
		arg_n[digits] = (n % 10) + '0';
		n /= 10;
		digits--;
	}
	arg_n[digits] = n + '0';
	digits--;
	printf("%s\n", arg_n);
	return (arg_n);
}