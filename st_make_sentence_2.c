
#include "ft_printf.h"

char    *st_make_sentence_2(char *sentence, char *specifier, char *percent)
{
    char *str;

    if (*percent == '-')
	{
		percent++;
		str = st_set_rightspace(sentence, specifier, percent);
		if (*percent == '0')
			percent++;
	}
	else if (*percent == '0')
	{
		percent++;
		if (*percent == '-')
			str = st_set_rightspace(sentence, specifier, percent);
		else
			str = st_set_0(sentence, specifier, percent);
	}
	else
		str = st_set_leftspace(sentence, specifier, percent);
    return (str);
}