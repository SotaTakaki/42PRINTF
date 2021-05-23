/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_make_acc_else.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:41:04 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/24 00:48:18 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	st_make_acc_else(t_list *info)
{
	int		i;
	char	*tmp;

	if (info->str != NULL)
	{
		if (info->accuracy == 0 && *(info->str) == '0')
		{
			free(info->str);
			info->str = NULL;
			tmp = st_strdup("", info);
			info->str = tmp;
			info->sub_flag = 1;
		}
		if (info->accuracy > 0)
		{
			i = info->accuracy - st_strlen(info->str);
			st_join_str("0", info, i);
			if (i < 0 && info->specifier[0] == 's')
				st_cut_str(info);
		}
	}
}

void	st_cut_str(t_list *info)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(info->accuracy + 1);
	if (tmp == NULL)
	{
		info->error = 1;
		return ;
	}
	tmp[info->accuracy] = '\0';
	while (info->accuracy > 0)
	{
		tmp[i] = info->str[i];
		i++;
		info->accuracy--;
	}
	free(info->str);
	info->str = NULL;
	info->str = tmp;
}
