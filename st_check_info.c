#include "ft_printf.h"
char	*st_strchr(const char *str, const char *specifier, int chr);
char	*st_strstr(const char *str, const char *to_find);
void    st_check_flag(const char *percent, t_list *info);


void    st_check_info(const char *percent, t_list *info)
{
    st_check_flag(percent, info);
    info->specifier = st_strstr(percent, "diuxXcsp");
    info->period = st_strchr(percent, info->specifier, '.');
}

char	*st_strchr(const char *str, const char *specifier, int chr)
{
	size_t	i;

	i = 0;
	if (str == NULL || specifier == NULL)
		return (NULL);
	while (str[i] != specifier[0])
	{
		if (str[i] == chr)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*st_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str == NULL)
		return (NULL);
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

void    st_check_flag(const char *percent, t_list *info)
{
	int	i;

	i = 1;
	if (percent == NULL)
		return ;
	while (percent[i] == '0' || percent[i] == '-')
	{
		if (percent[i] == '0')
		{
			info->flag = 2;
			i++;
		}
		if (percent[i] == '-')
		{
			info->flag = 1;
			while(percent[i] == '0' || percent[i] == '-')
				i++;
		}
	}
	info->percent = &(info->percent[i - 1]);
}
/*	if ((percent[1] == '0' && percent[2] == '-') ||
		(percent[1] == '-' && percent[2] == '0'))
	{
		info->flag = 1;
		info->percent = &((info->percent)[2]);
	}
	else if (percent[1] == '0' && percent[2] != '-')
	{
		info->flag = 2;
		info->percent = &((info->percent)[1]);
	}
	else if (percent[1] == '-')
	{
        info->flag = 1;
		info->percent = &((info->percent)[1]);
	}
}*/
