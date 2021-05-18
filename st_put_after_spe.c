#include "ft_printf.h"

void	st_put_after_spe(t_list *info)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (info->specifier[i] != '\0')
	{
		if (info->specifier[i] == '%' && info->specifier[i + 1] != '%')
			break ;
		if (info->specifier[i] == '%' && info->specifier[i + 1] == '%')
		{
			i++;
			j++;
		}
		write(1, &(info->specifier[i]), 1);
		i++;
	}
	info->all_len += i - j - 1;
	info->percent = &(info->specifier[i]);
}
