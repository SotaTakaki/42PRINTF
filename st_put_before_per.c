
#include "ft_printf.h"

void	st_put_before_per(const char *format, t_list *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
			break ;
		if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
			j++;
		}
		write(1, &format[i], 1);
		i++;
	}
		info->all_len += i - j;
		info->percent = &format[i];
}
