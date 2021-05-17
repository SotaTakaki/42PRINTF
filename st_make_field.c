#include "ft_printf.h"
size_t    ft_strlen(char *s);
void    st_join_machine(int i, t_list *info);
char	*st_strjoin(char *s1, char *s2);
char	*ft_strdog(char *s1, char *s2, char *box);
char	*ft_strdup(char *src);

void    st_make_field(t_list *info)
{
    int i;

    i = info->field - ft_strlen(info->str);
    if (i > 0)
        st_join_machine(i, info);
}

void    st_join_machine(int i, t_list *info)
{
	char	*brank;
	char	*zero;

	brank = ft_strdup(" ");
	zero = ft_strdup("0");
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
