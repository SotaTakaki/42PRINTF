#include <stdio.h>
int	ft_printf(const char *format, ...);

int	main(void)
{
	ft_printf("ft:%s/n %daaa", "12345", 6789);
	printf("%s/n %daaa", "12345", 6789);
	return (0);
}
