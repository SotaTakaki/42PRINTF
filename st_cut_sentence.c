
#include "ft_printf.h"

char	*st_cut_sentence(char *sentence, char *specifier, char *period)
{
	char 	*str;
	char	*tmp;
	size_t	len;
	size_t	i;

	str = st_make_width(specifier, period);
	i = ft_atoi(str);
	len = ft_strlen(sentence);
	if (i >= len)
		return (sentence);
	tmp = (char *)malloc(i + 1);
	tmp[i] = '\0';
	i = 0;
	while (tmp[i] != '\0')
	{
		tmp[i] = *sentence;
		i++;
		sentence++;
	}
	return (tmp);
}