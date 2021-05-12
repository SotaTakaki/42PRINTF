
#include "ft_printf.h"

char	*st_set_leftspace(char *sentence, char *specifier, char *period)
{
	char 	*str;
	char	*tmp;
	size_t	len;
	size_t	i;

	str = st_make_width(specifier, period);
	if (str == NULL)
		return (sentence);
	i = ft_atoi(str);
	len = ft_strlen(sentence);
	tmp = ft_strdup(" ");
	while (len < i)
	{
		sentence = ft_strjoin(tmp, sentence);
		len++;
	}
	return (sentence);
}