#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("%000012u\n", 0);
	ft_printf("%000012u\n", 0);
	system("leaks a.out");
	return (0);
}
