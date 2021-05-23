/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_putchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:49:25 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/23 22:39:07 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	st_putchr(va_list *ap, t_list *info)
{
	unsigned char	cast_c;
	unsigned char	*c;

	cast_c = (unsigned char)va_arg(*ap, int);
	if (cast_c == '\0')
		info->null_flag = 1;
	else
	{
		c = (unsigned char *)malloc(sizeof(unsigned char) * 2);
		if (c == NULL)
			info->error = 1;
		else
		{
			c[0] = cast_c;
			c[1] = '\0';
			info->str = (char *)c;
		}
	}
}
