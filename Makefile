# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 20:20:55 by ecarvalh          #+#    #+#              #
#    Updated: 2023/12/14 20:00:21 by anon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
RM		= rm -f
SRCS	=	$(wildcard lib/ft_*.c) \
			$(wildcard fun/ft_*.c) \
			$(wildcard ft_*.c)
OBJS	= $(SRCS:.c=.o)
CFLAGS	= -Wall -Wextra -Werror -I.
TARGET	= libftprintf.a

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rc $(TARGET) $(OBJS)

%.o:  %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

bonus: $(TARGET)

.PHONY: all clean fclean re
