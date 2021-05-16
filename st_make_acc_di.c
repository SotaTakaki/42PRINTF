#include "ft_printf.h"
size_t    ft_strlen(char *s);
char	*st_strjoin(char *s1, char *s2);
char	*ft_strdog(char *s1, char *s2, char *box);
char	*ft_strdup(char *src);

void    st_make_acc_di(t_list *info)
{
	int		i;
	char	*zero;

	i = info->accuracy - ft_strlen(info->str);
	zero = ft_strdup("0");
    if (info->accuracy != -1)
	{
		if (info->accuracy == 0 && info->str[0] == '0')
		{
			free(info->str);
			info->str = ft_strdup("");
		}
		while (i > 0)
		{
			info->str = st_strjoin(zero, info->str);
			i--;
			info->sub_flag = 1;
		}
	}
	free(zero);
	zero = NULL;
	if (info->minus == 1)
		info->str = st_strjoin("-", info->str);
}

size_t	ft_strlen(char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

char	*st_strjoin(char *s1, char *s2)
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
	free(s2);
	s2 = NULL;
	return (box);
}

char	*ft_strdog(char *s1, char *s2, char *box)
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

char	*ft_strdup(char *src)
{
	char	*box;
	int		i;

	box = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (box == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		box[i] = src[i];
		i++;
	}
	box[i] = '\0';
	return (box);
}