#include "ft_printf.h"
size_t    ft_strlen(char *s);
void    st_join_machine(int i, t_list *info);
char	*st_strjoin(char *s1, char *s2);
char	*st_strjoin2(char *s1, char *s2);
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
    if (info->flag == 0 || (info->flag == 2 && info->sub_flag == 1))
        {
            while (i > 0)
            {
                info->str = st_strjoin(" ", info->str);
                i--;
            }
        }
        else if (info->flag == 1)
         {
            while (i > 0)
            {
                info->str = st_strjoin2(info->str, " ");
                i--;
            }
        }
        else
            while (i > 0)
            {
                info->str = st_strjoin("0", info->str);
                i--;
            }
}

char	*st_strjoin2(char *s1, char *s2)
{
	size_t	len_total;
	char	*box;

	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	len_total = ft_strlen(s1) + ft_strlen(s2);
	box = (char *)malloc(len_total * sizeof(char) + 1);
	if (box == NULL)
		return (NULL);
	box = ft_strdog(s1, s2, box);
	free(s1);
	s1 = NULL;
	return (box);
}