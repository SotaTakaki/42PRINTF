#include "ft_printf.h"
void    st_join_machine(int i, t_list *info);

void    st_make_field(t_list *info)
{
    int i;

    i = info->field - st_strlen(info->str);
    if (i > 0)
        st_join_machine(i, info);
}

void    st_join_machine(int i, t_list *info)
{
	char	*brank;
	char	*zero;

	brank = st_strdup(" ");
	zero = st_strdup("0");
	if (info->flag == 0 || (info->flag == 2 && info->accuracy != -1))// && (info->sub_flag != -1))
    {
    	while (i > 0)
        {
        	info->str = st_strjoin(brank, info->str);
            i--;
        }
	}
	else if (info->flag == 1)// && info->zero_flag == 0)
    {
    	while (i > 0)
        {
        	info->str = st_strjoin(info->str, brank);
            i--;
        }
	}
    else if/* ((info->specifier[0] == 'd' || info->specifier[0] == 'i' || info->specifier[0] == 's') &&*/ ((info->accuracy == -1) || (info->sub_flag != 1))
	{
    	while (i - info->minus > 0)
        {
        	info->str = st_strjoin(zero, info->str);
            i--;
        }
	}
	free(brank);
	brank = NULL;
	free(zero);
	zero = NULL;
}
