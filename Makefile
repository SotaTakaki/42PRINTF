# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stakaki <stakaki@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/09 01:35:42 by stakaki           #+#    #+#              #
#    Updated: 2021/05/17 08:46:18 by stakaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c\
		st_initialize.c\
		st_put_before_per.c\
		st_check_info.c\
		st_set_width.c\
		st_put_after_spe.c\
		st_make_str.c\
		st_itoa_di.c\
		st_itoa_u.c\
		st_putchr.c\
		st_putstr.c\
		st_set_x.c\
		st_set_xx.c\
		st_set_p.c\
		st_make_acc_di.c\
		st_make_acc_else.c\
		st_make_acc_s.c\
		st_make_field.c\
		st_forget_info.c\

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
