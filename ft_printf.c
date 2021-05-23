/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:52:36 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/23 22:37:47 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	info;
	int		i;

	i = 0;
	st_initialize(&info);
	st_put_before_per(format, &info);
	if (info.percent == NULL)
		return (info.all_len);
	va_start(ap, format);
	while (*(info.percent) != '\0')
	{
		st_check_info(info.percent, &info);
		st_set_width(&info, &ap);
		i = st_make_str(&info, &ap);
		if (i == 1)
			return (-1);
		st_put_after_spe(&info);
		st_forget_info(&info);
	}
	va_end(ap);
	return (info.all_len);
}
