/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:52:36 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/12 17:11:37 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//ft_set_str:先頭の42を出せるようにしたい
//uのマイナス時の挙動

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;
	char	*percent;
	char	*specifier;
	char	*period;
	char	*sentence;

	sentence = NULL;
	percent = st_strchr(format, '%');
	len = st_put_before_per(format, percent);
	va_start(ap, format);
	while (percent)
	{
		percent++;
		specifier = st_strstr(percent, "diuxXcsp");
		sentence = st_set_str(&ap, specifier);
		period = st_strnchr(percent, '.', specifier);
		if (period != NULL)
			sentence = st_make_sentence_1(sentence, specifier, period, percent);
		else
			sentence = st_make_sentence_2(sentence, specifier, percent);
		len += ft_strlen(sentence);
		write(1, sentence, ft_strlen(sentence));
		percent = st_strchr(specifier, '%');
		specifier++;
		free(sentence);
		sentence = NULL;
		if (percent)
		{
			while (specifier != percent)
			{
				write(1, specifier, 1);
				specifier++;
				len += 1;
			}
		}
	}
	while (*specifier != '\0')
	{
		write(1, specifier, 1);
		specifier++;
		len += 1;
	}
	write(1, "\0", 1);
	va_end(ap);
	return (len);
}
