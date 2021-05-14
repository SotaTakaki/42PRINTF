
#include "ft_printf.h"

char    *st_make_sentence_1(char *sentence, char *specifier, char *period, char *percent)
{
    char *str;

    if (*specifier == 'c' || *specifier == 's')
		str = st_cut_sentence(sentence, specifier, period);
	else
    	str = st_set_0(sentence, specifier, period);
	if (*percent == '-')
	{
		percent++;
		str = st_set_rightspace(str, period, percent);
		if (*percent == '0')
			percent++;
	}
	else if (*percent == '0')
	{
		percent++;
		if (*percent == '-')
		    str = st_set_rightspace(str, period, percent);
	}
	else
		str = st_set_leftspace(str, period, percent);
    return (str);
}