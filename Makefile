# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/09 01:35:42 by stakaki           #+#    #+#              #
#    Updated: 2021/04/26 23:49:50 by stakaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c\
		st_set_str.c\
		st_put_before_per.c\
		st_strchr.c\
		st_strnchr.c\
		st_itoa_di.c\
		st_itoa_u.c\
		st_putchr.c\
		st_putstr.c\
		ft_count_digits.c\
		ft_malloc.c\
		ft_strdup.c\
		ft_strlen.c\
		st_strstr.c\
		st_set_0.c\
		st_set_leftspace.c\
		st_make_width.c\
		st_set_rightspace.c\
		st_cut_sentence.c\
		ft_atoi.c\
		ft_strjoin.c\
		ft_strdog.c\
		st_set_x.c\
		st_set_X.c\
		st_set_p.c\
		st_count_sixteen.c\

OBJCS = $(SRCS:.c=.o)

INCLUDE = ft_printf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME): $(OBJCS)
	ar rc $(NAME) $(OBJCS)

bonus: $(OBJCS)
	ar rc $(NAME) $(OBJCS)

clean:
	rm -f $(OBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
