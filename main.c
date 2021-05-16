#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("%p %x %5.9d789\n", "12345", "6789", 123456);
	ft_printf("%p %x %5.9d789", "12345", "6789", 123456);
	return (0);
}
