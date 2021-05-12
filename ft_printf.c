/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:52:36 by stakaki           #+#    #+#             */
/*   Updated: 2021/05/08 22:48:47 by stakaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//ft_set_str:先頭の42を出せるようにしたい
//uのマイナス時の挙動
int	main(void)
{
	ft_printf("%10.7d\n", 12345);
	printf("%10.7d\n", 12345);
	return (0);
}

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
	percent++;
	specifier = st_strstr(percent, "diuxXcsp");
	sentence = ft_set_str(ap, specifier);
	period = st_strnchr(percent, '.', specifier);
	if (period != NULL)
	{
		if (*specifier == 'c' || *specifier == 's')
			sentence = st_cut_sentence(sentence, specifier, period);
		else
			sentence = st_set_0(sentence, specifier, period);
		if (*percent == '-')
		{
			percent++;
			sentence = st_set_rightspace(sentence, period, percent);
			if (*percent == '0')
				percent++;
		}
		else if (*percent == '0')
		{
			percent++;
			if (*percent == '-')
				sentence = st_set_rightspace(sentence, period, percent);
		}
		else
			sentence = st_set_leftspace(sentence, period, percent);
	}
	else
	{
		if (*percent == '-')
		{
			percent++;
			sentence = st_set_rightspace(sentence, specifier, percent);
			if (*percent == '0')
				percent++;
		}
		else if (*percent == '0')
		{
			percent++;
			if (*percent == '-')
				sentence = st_set_rightspace(sentence, specifier, percent);
			else
				sentence = st_set_0(sentence, specifier, percent);
		}
		else
			sentence = st_set_leftspace(sentence, specifier, percent);
	}
	len += ft_strlen(sentence);
	write(1, sentence, ft_strlen(sentence));
	percent = st_strchr(specifier, '%');
	specifier++;
	if (percent)
	{
		while (specifier != percent)
		{
			write(1, specifier, 1);
			specifier++;
			len += 1;
		}
	}
	else
	{
		while (*specifier != '\0')
		{
			write(1, specifier, 1);
			specifier++;
			len += 1;
		}
	}
	write(1, '\0', 1);
	va_end(ap);
	return (len);
}