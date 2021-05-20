/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_set_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:50:08 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/20 12:45:27 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
int	st_count_sixteen_ptr_t(uintptr_t num);

char	*st_set_p(va_list *ap, t_list *info)
{
	uintptr_t	num;
	int			digits;
	const char	set[17] = "0123456789abcdef";
	char		*str;

	num = va_arg(*ap, uintptr_t);
	digits = st_count_sixteen_ptr_t(num) + 2;
	str = (char *)malloc(digits + 1);
	if (str == NULL)
	{
		info->error = 1;
		return (NULL);
	}
	str[digits] = '\0';
	digits--;
	while (num > 16)
	{
		str[digits] = set[num % 16];
		num /= 16;
		digits--;
	}
	str[digits] = set[num];
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

int	st_count_sixteen_ptr_t(uintptr_t num)
{
	int	digits;

	digits = 1;
	while (num > 16)
	{
		num /= 16;
		digits++;
	}
	return (digits);
}

int	st_count_sixteen(unsigned int num)
{
	int	digits;

	digits = 1;
	while (num > 16)
	{
		num /= 16;
		digits++;
	}
	return (digits);
}
