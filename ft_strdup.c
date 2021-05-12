
#include "ft_printf.h"

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