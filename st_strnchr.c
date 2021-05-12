
#include "ft_printf.h"

char	*st_strnchr(const char *str, int chr, char *end)
{
	size_t	i;

	i = 0;
	while (str[i] != *end)
	{
		if (str[i] == chr)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}