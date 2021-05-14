
#include "ft_printf.h"

char	*st_strchr(const char *str, int chr)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}