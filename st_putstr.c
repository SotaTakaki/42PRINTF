/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:49:44 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/20 12:49:19 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	st_putstr(va_list *ap, t_list *info)
{
	char	*tmp;

	tmp = (char *)va_arg(*ap, const char *);
	if (tmp == NULL)
		info->str = st_strdup("(null)", info);
	else
		info->str = st_strdup(tmp, info);
}
