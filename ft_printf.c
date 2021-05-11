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

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...);
char	*st_strchr(const char *str, int chr);
char	*st_strnchr(const char *str, int chr, char *end);
size_t	st_put_before_per(const char *format, char *judge_percent);
char	*ft_set_str(va_list ap, char *specifier);
char	*st_itoa_di(va_list ap);
char	*st_itoa_u(va_list ap);
unsigned char	*st_putchr(va_list ap);
char	*st_putstr(va_list ap);
int		ft_count_digits(int n);
char	*ft_malloc(int n);
char	*st_strstr(const char *str, const char *to_find);
char	*ft_strdup(char *src);
size_t	ft_strlen(char *s);
int	ft_atoi(char *str);
char	*st_set_0(char *sentence, char *specifier, char *period);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdog(char *s1, char *s2, char *box);
char	*st_make_width(char *specifier, char *period);
char	*st_cut_sentence(char *sentence, char *specifier, char *period);
char	*st_set_leftspace(char *sentence, char *specifier, char *period);
char	*st_set_x(va_list ap);
char	*st_set_X(va_list ap);
char	*st_set_p(va_list ap);
int	st_count_sixteen(unsigned int num);
char	*st_set_rightspace(char *sentence, char *specifier, char *period);

int	main(void)
{
	char	c;

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
	//u -> ft_itoa() (負の値を引数にすると、 そのビット表現である2の補数をunsigned intとして解釈した値に変換する。)
	//to do:uのマイナスの値の時の挙動がおかしい
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

char	*ft_set_str(va_list ap, char *specifier)
{
	if (*specifier == 'd' || *specifier == 'i')
		return (st_itoa_di(ap));
	else if (*specifier == 'u') //先頭の42がでない
		return(st_itoa_u(ap));
	else if (*specifier == 'c')
		return (st_putchr(ap));
	else if (*specifier == 's')
		return (st_putstr(ap));
	else if (*specifier == 'x')
		return (st_set_x(ap));
	else if (*specifier == 'X')
		return (st_set_X(ap));
	else if (*specifier == 'p')
		return (st_set_p(ap));
}

size_t	st_put_before_per(const char *start, char *percent)
{
	size_t	len;

	len = percent - start;
	write(1, start, len);
	return (len);	
}

char	*st_strchr(const char *str, int chr)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return ((char *)&str[i]);
		i++;
	}
	return ((char *)&str[i]);
}

char	*st_strnchr(const char *str, int chr, char *end)
{
	size_t	i;

	i = 0;
	while (str[i] != *end)
	{
		if (str[i] == chr)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*st_itoa_di(va_list ap)
{
	int		n;
	int		digits;
	int		n_dev;
	char	*arg_n;

	n = va_arg(ap, int);
	digits = ft_count_digits(n) - 1;
	n_dev = (int)n;
	arg_n = ft_malloc(n);
	if (arg_n == NULL)
		return (NULL);
	if (n_dev < 0)
		n_dev = n_dev * -1;
	while (n_dev >= 10)
	{
		arg_n[digits] = (n_dev % 10) + '0';
		n_dev /= 10;
		digits--;
	}
	arg_n[digits] = n_dev + '0';
	digits--;
	if (n < 0)
		arg_n[digits] = '-';
	return (arg_n);
}

char	*st_itoa_u(va_list ap)
{
	unsigned int	n;
	int				digits;
	char			*arg_n;

	n = va_arg(ap, unsigned int);
	digits = ft_count_digits(n) - 1;
	arg_n = ft_malloc(n);
	if (arg_n == NULL)
		return (NULL);
	while (n >= 10)
	{
		arg_n[digits] = (n % 10) + '0';
		n /= 10;
		digits--;
	}
	arg_n[digits] = n + '0';
	digits--;
	printf("%s\n", arg_n);
	return (arg_n);
}

unsigned char	*st_putchr(va_list ap)
{
	unsigned char	cast_c;
	unsigned char	*c;

	cast_c = va_arg(ap, int);
	c = (char *)malloc(sizeof(char) * 2);
	if (c == NULL)
		return (NULL);
	c[0] = cast_c;
	c[1] = '\0';
	return (c);
}

char	*st_putstr(va_list ap)
{
	char	*tmp;
	char	*str;

	tmp = va_arg(ap, char*);
	str = ft_strdup(tmp);
	return (str);
}

int	ft_count_digits(int	n)
{
	long	n_dev;
	int		digits;

	n_dev = n;
	digits = 0;
	if (n == 0)
		return (1);
	if (n_dev < 0)
	{
		n_dev = n_dev * -1;
		digits++;
	}
	while (n_dev > 0)
	{
		n_dev /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_malloc(int n)
{
	int		digits;
	char	*range;

	digits = ft_count_digits(n);
	range = (char *)malloc(digits * sizeof(char) + 1);
	if (range == NULL)
		return (NULL);
	range[digits] = '\0';
	return (range);
}

char	*ft_strdup(char *src)
{
	char	*box;
	int		i;

	box = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (box == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		box[i] = src[i];
		i++;
	}
	box[i] = '\0';
	return (box);
}

size_t	ft_strlen(char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

char	*st_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] != to_find[j] && to_find[j] != '\0') 
			j++;
		if (str[i] == to_find[j])
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*st_set_0(char *sentence, char *specifier, char *period)
{
	char 	*str;
	char	*tmp;
	size_t	len;
	size_t	i;

	str = st_make_width(specifier, period);
	i = ft_atoi(str);
	len = ft_strlen(sentence);
	tmp = ft_strdup("0");
	while (len < i)
	{
		sentence = ft_strjoin(tmp, sentence);
		len++;
	}
	return (sentence);
}

char	*st_set_leftspace(char *sentence, char *specifier, char *period)
{
	char 	*str;
	char	*tmp;
	size_t	len;
	size_t	i;

	str = st_make_width(specifier, period);
	if (str == NULL)
		return (sentence);
	i = ft_atoi(str);
	len = ft_strlen(sentence);
	tmp = ft_strdup(" ");
	while (len < i)
	{
		sentence = ft_strjoin(tmp, sentence);
		len++;
	}
	return (sentence);
}

char	*st_set_rightspace(char *sentence, char *specifier, char *period)
{
	char 	*str;
	char	*tmp;
	size_t	len;
	size_t	i;

	str = st_make_width(specifier, period);
	if (str == NULL)
		return (sentence);
	i = ft_atoi(str);
	len = ft_strlen(sentence);
	tmp = ft_strdup(" ");
	while (len < i)
	{
		sentence = ft_strjoin(sentence, tmp);
		len++;
	}
	return (sentence);
}

char	*st_cut_sentence(char *sentence, char *specifier, char *period)
{
	char 	*str;
	char	*tmp;
	size_t	len;
	size_t	i;

	str = st_make_width(specifier, period);
	i = ft_atoi(str);
	len = ft_strlen(sentence);
	if (i >= len)
		return (sentence);
	tmp = (char *)malloc(i + 1);
	tmp[i] = '\0';
	i = 0;
	while (tmp[i] != '\0')
	{
		tmp[i] = *sentence;
		i++;
		sentence++;
	}
	return (tmp);
}

char	*st_make_width(char *specifier, char *period)
{
	char 	*str;
	ssize_t	len;
	ssize_t	i;

	if (*period == '.')
		period++;
	len = specifier - period;
	if (len == -1)
		return (NULL);
	str = (char *)malloc(len + 1);
	str[len] = '\0';
	i = 0;
	while (period != specifier)
	{
		str[i] = *period;
		period++;
		i++;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int			i;
	int			minus;
	size_t		answer;

	i = 0;
	minus = 1;
	answer = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			minus = minus * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		answer = answer * 10;
		answer += str[i] - '0';
		i++;
	}
	return ((int)(answer * minus));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len_total;
	char	*box;

	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	i = 0;
	len_total = ft_strlen(s1) + ft_strlen(s2);
	box = (char *)malloc(len_total * sizeof(char) + 1);
	if (box == NULL)
		return (NULL);
	box = ft_strdog(s1, s2, box);
	return (box);
}

char	*ft_strdog(char *s1, char *s2, char *box)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		box[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		box[i] = s2[j];
		i++;
		j++;
	}
	box[i] = '\0';
	return (box);
}

char	*st_set_x(va_list ap)
{
	unsigned int	num;
	int	digits;
	char			set[17] = "0123456789abcdef";
	char			*str;

	num = va_arg(ap, unsigned int);
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

char	*st_set_X(va_list ap)
{
	unsigned int	num;
	int	digits;
	char			set[17] = "0123456789ABCDEF";
	char			*str;

	num = va_arg(ap, unsigned int);
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

char	*st_set_p(va_list ap)
{
	unsigned int	num;
	int	digits;
	char			set[17] = "0123456789ABCDEF";
	char			*str;

	num = va_arg(ap, unsigned int);
	digits = st_count_sixteen(num) + 2;
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
	str[0] = '0';
	str[1] = '0';
	return (str);
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