
#include "ft_printf.h"
char	*st_strjoin(char *s1, char *s2);

void	st_putstr(va_list *ap, t_list *info)
{
	char	*tmp;

	tmp = (char *)va_arg(*ap, char*);
	info->str = tmp;
}

/*char	*st_strdup(char *src)
{
	char	*box;
	size_t	i;

	box = (char *)malloc(sizeof(char) * len + 1);
	if (box == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		box[i] = src[i];
		i++;
	}
	box[i] = '\0';
	return (box);
}*/