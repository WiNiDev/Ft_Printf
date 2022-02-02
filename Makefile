#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 12:00:18 by marvin            #+#    #+#              #
#    Updated: 2021/11/21 14:45:14 by mberthoi         ###   ########lyon.fr    #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

INCLUDE = ./include/ft_printf.h

CC	=	gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/ft_printf.c srcs/ft_utils.c srcs/ft_scnd_utils.c srcs/ft_convert_char.c srcs/ft_convert_digit.c srcs/ft_convert_scnd_digit.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%o : %c $(INCLUDE)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re
