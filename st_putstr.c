
#include "ft_printf.h"

void	st_putstr(va_list *ap, t_list *info)
{
	char	*tmp;

	tmp = (char *)va_arg(*ap, const char*);
	if (tmp == NULL)
		info->str = st_strdup("(null)");
	else
		info->str = st_strdup(tmp);
}
