
#include "ft_printf.h"

char	*st_set_0(char *sentence, char *specifier, char *period)
{
	char 	*str;
	char	*tmp;
	size_t	len;
	size_t	i;

	str = st_make_width(specifier, period);
	i = ft_atoi(str);
	len = ft_strlen(sentence);
	tmp = ft_strdup("0");
	while (len < i)
	{
		sentence = ft_strjoin(tmp, sentence);
		len++;
	}
	return (sentence);
}