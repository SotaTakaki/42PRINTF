/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_itoa_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:39:50 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/19 15:21:47 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
int		st_count_digits(int	n);
char	*st_malloc(int n);

char	*st_itoa_di(va_list *ap, t_list *info)
{
	long long		n;
	long long		digits;
	long long		n_dev;
	char			*arg_n;

	n = va_arg(*ap, int);
	digits = st_count_digits(n) - 1;
	n_dev = n;
	arg_n = st_malloc(n);
	if (arg_n == NULL)
		return (NULL);
	if (n_dev < 0)
	{
		n_dev = n_dev * -1;
		info->minus += 1;
	}
	while (n_dev >= 10)
	{
		arg_n[digits] = (n_dev % 10) + '0';
		n_dev /= 10;
		digits--;
	}
	arg_n[digits] = n_dev + '0';
	return (arg_n);
}

int	st_count_digits(int	n)
{
	long long	n_dev;
	int			digits;

	n_dev = n;
	digits = 0;
	if (n == 0)
		return (1);
	if (n_dev < 0)
	{
		n_dev = n_dev * -1;
	}
	while (n_dev > 0)
	{
		n_dev /= 10;
		digits++;
	}
	return (digits);
}

char	*st_malloc(int n)
{
	int		digits;
	char	*range;

	digits = st_count_digits(n);
	range = (char *)malloc(digits * sizeof(char) + 1);
	if (range == NULL)
		return (NULL);
	range[digits] = '\0';
	return (range);
}
