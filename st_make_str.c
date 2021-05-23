/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_make_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:47:55 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/23 23:03:23 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
void	st_set_str(t_list *info, va_list *ap);
int		st_write_null(t_list *info);

int	st_make_str(t_list *info, va_list *ap)
{
	st_set_str(info, ap);
	if (info->null_flag == 1)
		return (st_write_null(info));
	if (info->specifier[0] == 'd' || info->specifier[0] == 'i')
		st_make_acc_di(info);
	else if (info->specifier[0] == 's')
		st_make_acc_s(info);
	else
		st_make_acc_else(info);
	st_make_field(info);
	if (info->error == 1)
		return (1);
	info->all_len += st_strlen(info->str);
	if (info->all_len >= INT_MAX)
		return (1);
	info->str_len = st_strlen(info->str);
	write(1, info->str, info->str_len);
	return (0);
}

void	st_set_str(t_list *info, va_list *ap)
{
	if (*(info->specifier) == 'd' || *(info->specifier) == 'i')
		info->str = st_itoa_di(ap, info);
	else if (*(info->specifier) == 'u')
		info->str = st_itoa_u(ap, info);
	else if (*(info->specifier) == 'c')
		st_putchr(ap, info);
	else if (*(info->specifier) == 's')
		st_putstr(ap, info);
	else if (*(info->specifier) == 'x')
		info->str = st_set_x(ap, info);
	else if (*(info->specifier) == 'X')
		info->str = st_set_xx(ap, info);
	else if (*(info->specifier) == 'p')
		info->str = st_set_p(ap, info);
}

int	st_write_null(t_list *info)
{
	if (info->field != 0)
	{
		if (info->flag == 1)
			write(1, "", 1);
		while (info->field - 1 > 0)
		{
			write(1, " ", 1);
			info->field -= 1;
			info->all_len += 1;
		}
		if (info->flag != 1)
			write(1, "", 1);
		info->all_len += 1;
	}
	else
	{
		write(1, "", 1);
		info->all_len += 1;
	}
	if (info->all_len >= INT_MAX)
		return (1);
	else
		return (0);
}
