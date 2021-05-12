
#include "ft_printf.h"

char	*ft_malloc(int n)
{
	int		digits;
	char	*range;

	digits = ft_count_digits(n);
	range = (char *)malloc(digits * sizeof(char) + 1);
	if (range == NULL)
		return (NULL);
	range[digits] = '\0';
	return (range);
}