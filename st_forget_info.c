/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_forget_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:38:33 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/19 14:39:01 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	st_forget_info(t_list *info)
{
	free(info->str);
	info->str = NULL;
	info->period = NULL;
	info->specifier = NULL;
	info->flag = 0;
	info->sub_flag = 0;
	info->zero_flag = 0;
	info->field = 0;
	info->accuracy = -1;
	info->minus = 0;
	info->str_len = 0;
}
