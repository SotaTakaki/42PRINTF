
#include "ft_printf.h"
unsigned int	st_count_digits_unsigned(unsigned int n);
char	*st_malloc_unsigned(unsigned int n);


char	*st_itoa_u(va_list *ap)
{
	unsigned int		n;
	int					digits;
	char				*arg_n;

	n = va_arg(*ap, unsigned int);
	digits = st_count_digits_unsigned(n) - 1;
	arg_n = st_malloc_unsigned(n);
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
	return (arg_n);
}

unsigned int	st_count_digits_unsigned(unsigned int n)
{
	unsigned int	n_dev;
	unsigned int	digits;

	n_dev = n;
	digits = 0;
	if (n == 0)
		return (1);
	while (n_dev > 0)
	{
		n_dev /= 10;
		digits++;
	}
	return (digits);
}

char	*st_malloc_unsigned(unsigned int n)
{
	unsigned int digits;
	char	*range;

	digits = st_count_digits_unsigned(n);
	range = (char *)malloc(digits * sizeof(char) + 1);
	if (range == NULL)
		return (NULL);
	range[digits] = '\0';
	return (range);
}