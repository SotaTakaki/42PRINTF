/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_putchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:49:25 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/20 12:42:27 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned char	*st_putchr(va_list *ap, t_list *info)
{
	unsigned char	cast_c;
	unsigned char	*c;

	cast_c = va_arg(*ap, int);
	c = (unsigned char *)malloc(sizeof(unsigned char) * 2);
	if (c == NULL)
	{
		info->error = 1;
		return (NULL);
	}
	c[0] = cast_c;
	c[1] = '\0';
	return (c);
}
