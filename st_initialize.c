/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:39:10 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/20 12:18:12 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	st_initialize(t_list *info)
{
	info->str = NULL;
	info->percent = NULL;
	info->period = NULL;
	info->specifier = NULL;
	info->flag = 0;
	info->sub_flag = 0;
	info->zero_flag = 0;
	info->field = 0;
	info->accuracy = -1;
	info->minus = 0;
	info->error = 0;
	info->str_len = 0;
	info->all_len = 0;
}
