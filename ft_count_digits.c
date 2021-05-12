
#include "ft_printf.h"

int	ft_count_digits(int	n)
{
	long	n_dev;
	int		digits;

	n_dev = n;
	digits = 0;
	if (n == 0)
		return (1);
	if (n_dev < 0)
	{
		n_dev = n_dev * -1;
		digits++;
	}
	while (n_dev > 0)
	{
		n_dev /= 10;
		digits++;
	}
	return (digits);
}