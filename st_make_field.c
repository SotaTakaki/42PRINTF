/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_make_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:45:05 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/19 16:48:12 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
void	st_join_machine(int i, t_list *info);

void	st_make_field(t_list *info)
{
	int	i;

	i = info->field - st_strlen(info->str);
	if (info->minus == 1 && info->accuracy == -1)
	{
		i -= 1;
		if (info->flag == 0)
			info->str = st_strjoin("-", info->str);
	}
	if (i > 0)
		st_join_machine(i, info);
	if (info->flag != 0 && info->accuracy == -1 && info->minus == 1)
		info->str = st_strjoin("-", info->str);
}

void	st_join_machine(int i, t_list *info)
{
	char	*brank;
	char	*zero;

	brank = st_strdup(" ");
	zero = st_strdup("0");
	if (info->flag == 0 || (info->flag == 2 && info->accuracy != -1))
		st_join_str(brank, info, i);
	else if (info->flag == 1)
	{
		while (i > 0)
		{
			info->str = st_strjoin(info->str, brank);
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
		info->str = st_strjoin(join, info->str);
		i--;
	}
}
