# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 20:20:55 by ecarvalh          #+#    #+#              #
#    Updated: 2023/11/13 13:08:05 by ecarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(filter-out $(wildcard ./ft_*_bonus.c), $(wildcard ./ft_*.c))
OBJS	= $(SRCS:.c=.o)
B_SRCS	= $(wildcard ./ft_*_bonus.c)
B_OBJS	= $(B_SRCS:.c=.o)
CFLAGS	= -Wall -Wextra -Werror -I.
NAME	= libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS)

.PHONY: all clean fclean re
