# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 20:20:55 by ecarvalh          #+#    #+#              #
#    Updated: 2024/01/09 14:39:50 by ecarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
RM		= rm -f
SDIR	= eval fun .
SRCS	= $(foreach dir,$(SDIR),$(wildcard $(dir)/ft_*.c))
ODIR	= objs
OBJS    = $(addprefix $(ODIR)/,$(SRCS:.c=.o))
CFLAGS	= -Wall -Wextra -Werror -I. -g
NAME	= libftprintf.a

vpath %.c $(SDIR)

all: $(NAME)

test: all
	$(CC) $(CFLAGS) main.c $(NAME) && ./a.out

$(NAME): $(OBJS)
	ar rc $(NAME) $^

$(ODIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(ODIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re
