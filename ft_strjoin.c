
#include "ft_printf.h"
char	*ft_strdog(char *s1, char *s2, char *box);

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_total;
	char	*box;

	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	len_total = ft_strlen(s1) + ft_strlen(s2);
	box = (char *)malloc(len_total * sizeof(char) + 1);
	if (box == NULL)
		return (NULL);
	box = ft_strdog(s1, s2, box);
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