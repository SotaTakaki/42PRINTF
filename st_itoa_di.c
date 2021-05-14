
#include "ft_printf.h"

char	*st_itoa_di(va_list *ap)
{
	int		n;
	int		digits;
	int		n_dev;
	char	*arg_n;

	n = va_arg(*ap, int);
	digits = ft_count_digits(n) - 1;
	n_dev = (int)n;
	arg_n = ft_malloc(n);
	if (arg_n == NULL)
		return (NULL);
	if (n_dev < 0)
		n_dev = n_dev * -1;
	while (n_dev >= 10)
	{
		arg_n[digits] = (n_dev % 10) + '0';
		n_dev /= 10;
		digits--;
	}
	arg_n[digits] = n_dev + '0';
	digits--;
	if (n < 0)
		arg_n[digits] = '-';
	return (arg_n);
}