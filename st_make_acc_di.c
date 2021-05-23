/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_make_acc_di.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:40:32 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/24 00:36:08 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	st_make_acc_di(t_list *info)
{
	int		i;
	char	*zero;

	i = info->accuracy - st_strlen(info->str);
	zero = st_strdup("0", info);
	if (info->accuracy != -1)
	{
		if (info->accuracy == 0 && info->str[0] == '0')
		{
			free(info->str);
			info->str = NULL;
			info->str = st_strdup("", info);
			info->sub_flag = 1;
		}
		while (i > 0)
		{
			info->str = st_strjoin(zero, info->str, info);
			i--;
		}
		if (info->minus == 1)
			info->str = st_strjoin("-", info->str, info);
	}
	free(zero);
	zero = NULL;
}

int	st_strlen(char *s)
{
	int	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

char	*st_strjoin(char *s1, char *s2, t_list *info)
{
	size_t	len_total;
	char	*box;

	if (s1 == NULL || s2 == NULL)
		return (st_strdup("", info));
	len_total = st_strlen(s1) + st_strlen(s2);
	box = (char *)malloc(len_total * sizeof(char) + 1);
	if (box == NULL)
	{
		info->error = 1;
		return (NULL);
	}
	box = st_strdog(s1, s2, box);
	free(s2);
	s2 = NULL;
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

char	*st_strdup(char *src, t_list *info)
{
	char	*box;
	int		i;

	box = (char *)malloc(sizeof(char) * (st_strlen(src) + 1));
	if (box == NULL)
	{
		info->error = 1;
		return (NULL);
	}
	i = 0;
	while (src[i] != '\0')
	{
		box[i] = src[i];
		i++;
	}
	box[i] = '\0';
	return (box);
}
