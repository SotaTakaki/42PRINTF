
#include "ft_printf.h"

char	*st_make_width(char *specifier, char *period)
{
	char 	*str;
	ssize_t	len;
	ssize_t	i;

	if (*period == '.')
		period++;
	len = specifier - period;
	if (len == -1)
		return (NULL);
	str = (char *)malloc(len + 1);
	str[len] = '\0';
	i = 0;
	while (period != specifier)
	{
		str[i] = *period;
		period++;
		i++;
	}
	return (str);
}