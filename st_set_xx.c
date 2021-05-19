/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_set_xx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:52:06 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/19 15:18:45 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*st_set_xx(va_list *ap)
{
	unsigned int	num;
	int				digits;
	const char		set[17] = "0123456789ABCDEF";
	char			*str;

	num = va_arg(*ap, unsigned int);
	digits = st_count_sixteen(num);
	str = (char *)malloc(digits + 1);
	str[digits] = '\0';
	digits--;
	while (num > 16)
	{
		str[digits] = set[num % 16];
		num /= 16;
		digits--;
	}
	str[digits] = set[num];
	return (str);
}
