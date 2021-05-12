
#include "ft_printf.h"

char	*st_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] != to_find[j] && to_find[j] != '\0') 
			j++;
		if (str[i] == to_find[j])
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}