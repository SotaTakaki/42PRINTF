
#include "ft_printf.h"

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