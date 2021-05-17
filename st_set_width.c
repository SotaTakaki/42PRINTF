#include "ft_printf.h"
int	st_atoi(const char *str);

void    st_set_width(t_list *info, va_list *ap)
{
	if (info->percent)
	{
    	if ((info->percent)[1] == '*')
		{
        	info->field = va_arg(*ap, int);
			if (info->field < 0)
			{
				info->flag = 1;
				info->field *= -1;
			}
		}
 	 	else
        	info->field = st_atoi(info->percent);
	}
	if (info->period)
	{
    	if ((info->period)[1] == '*')
      		info->accuracy = va_arg(*ap, int);
		else if ((info->period)[1] == (info->specifier)[0])
			info->accuracy = 0;
    	else
        	info->accuracy = st_atoi(info->period);
	}
}

int	st_atoi(const char *str)
{
	size_t		i;
	size_t		minus;
	size_t		answer;

	i = 1;
	minus = 1;
	answer = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			minus = minus * -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		answer = answer * 10;
		answer += str[i] - '0';
		i++;
	}
	return ((int)(answer * minus));
}
