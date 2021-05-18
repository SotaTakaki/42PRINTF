#include "ft_printf.h"

void    st_make_acc_di(t_list *info)
{
	int		i;
	char	*zero;

	i = info->accuracy - st_strlen(info->str);
	zero = st_strdup("0");
    if (info->accuracy != -1)
	{
		if (info->accuracy == 0 && info->str[0] == '0')
		{
			free(info->str);
			info->str = st_strdup("");
			info->sub_flag = 1;
		}
		while (i > 0)
		{
			info->str = st_strjoin(zero, info->str);
			i--;
		}
	if (info->minus == 1)
		info->str = st_strjoin("-", info->str);
	}
	free(zero);
	zero = NULL;
}

size_t	st_strlen(char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

char	*st_strjoin(char *s1, char *s2)
{
	size_t	len_total;
	char	*box;

	if (s1 == NULL || s2 == NULL)
		return (st_strdup(""));
	len_total = st_strlen(s1) + st_strlen(s2);
	box = (char *)malloc(len_total * sizeof(char) + 1);
	if (box == NULL)
		return (NULL);
	box = st_strdog(s1, s2, box);
//	free(s2);
//	s2 = NULL;
	return (box);
}

char	*st_strdog(char *s1, char *s2, char *box)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		box[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		box[i] = s2[j];
		i++;
		j++;
	}
	box[i] = '\0';
	return (box);
}

char	*st_strdup(char *src)
{
	char	*box;
	int		i;

	box = (char *)malloc(sizeof(char) * (st_strlen(src) + 1));
	if (box == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		box[i] = src[i];
		i++;
	}
	box[i] = '\0';
	return (box);
}
