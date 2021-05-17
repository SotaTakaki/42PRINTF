#include "ft_printf.h"

void    st_forget_info(t_list *info)
{
   // free(info->str);
    info->str = NULL;
    info->period = NULL;
    info->specifier = NULL;
    info->flag = 0;
    info->sub_flag = 0;
	info->zero_flag = 0;
    info->field = 0;
    info->accuracy = -1;
    info->minus = 0;
    info->str_len = 0;
}
