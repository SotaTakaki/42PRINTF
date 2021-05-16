#include "ft_printf.h"
size_t    ft_strlen(char *s);

void    st_make_acc_else(t_list *info)
{
    int     i;
    char    *tmp;

    i = info->accuracy - ft_strlen(info->str);
    if (i < 0)
    {
        tmp = (char *)malloc(info->accuracy + 1);
        tmp[info->accuracy] = '\0';
        i = 0;
        while (info->accuracy > 0)
        {
            tmp[i] = info->str[i];
            i++;
            info->accuracy--;
        }
        free(info->str);
        info->str = tmp;
    }
}