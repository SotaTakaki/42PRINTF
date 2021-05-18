#include "ft_printf.h"

void    st_make_acc_s(t_list *info)
{
    int     i;
	char	*tmp;

	if (info->accuracy == 0)
	{
		tmp = st_strdup("");
		info->str = tmp;
		info->sub_flag = 1;
	}
	else if (info->accuracy > 0)
    {
        i = info->accuracy - st_strlen(info->str);
		if (i < 0)
        {
			tmp = st_strdup(info->str);
            info->str = (char *)malloc(info->accuracy + 1);
            info->str[info->accuracy] = '\0';
            i = 0;
            while (info->accuracy > 0)
            {
                info->str[i] = tmp[i];
                i++;
                info->accuracy--;
            }
			free(tmp);
			tmp = NULL;
        }
    }
}
