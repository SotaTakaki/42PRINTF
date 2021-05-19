/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:49:44 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/19 15:18:12 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	st_putstr(va_list *ap, t_list *info)
{
	char	*tmp;

	tmp = (char *)va_arg(*ap, const char *);
	if (tmp == NULL)
		info->str = st_strdup("(null)");
	else
		info->str = st_strdup(tmp);
}
