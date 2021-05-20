/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_make_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:45:05 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/20 12:41:01 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
void	st_join_machine(int i, t_list *info);
char	*st_strjoin2(char *s1, char *s2, t_list *info);

void	st_make_field(t_list *info)
{
	int	i;

	i = info->field - st_strlen(info->str);
	if (info->minus == 1 && info->accuracy == -1)
	{
		i -= 1;
		if (info->flag == 0)
			info->str = st_strjoin("-", info->str, info);
	}
	if (i > 0)
		st_join_machine(i, info);
	if (info->flag != 0 && info->accuracy == -1 && info->minus == 1)
		info->str = st_strjoin("-", info->str, info);
}

void	st_join_machine(int i, t_list *info)
{
	char	*brank;
	char	*zero;

	brank = st_strdup(" ", info);
	zero = st_strdup("0", info);
	if (info->flag == 0 || (info->flag == 2 && info->accuracy != -1))
		st_join_str(brank, info, i);
	else if (info->flag == 1)
	{
		while (i > 0)
		{
			info->str = st_strjoin2(info->str, brank, info);
			i--;
		}
	}
	else if ((info->accuracy == -1) || (info->sub_flag != 1))
		st_join_str(zero, info, i);
	free(brank);
	brank = NULL;
	free(zero);
	zero = NULL;
}

void	st_join_str(char *join, t_list *info, int i)
{
	while (i > 0)
	{
		info->str = st_strjoin(join, info->str, info);
		i--;
	}
}

char	*st_strjoin2(char *s1, char *s2, t_list *info)
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
	free(s1);
	s2 = NULL;
	return (box);
}
