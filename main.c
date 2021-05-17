#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("%-00000-----*i", 12);
	ft_printf("ft:%-00000-----*i", 12);
	system("leaks a.out");
	return (0);
}
