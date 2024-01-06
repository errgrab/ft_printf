# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 20:20:55 by ecarvalh          #+#    #+#              #
#    Updated: 2024/01/05 19:02:52 by ecarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
RM		= rm -f
SDIR	= eval fun lib .
SRCS	= $(foreach dir,$(SDIR),$(wildcard $(dir)/ft_*.c))
ODIR	= objs
OBJS    = $(addprefix $(ODIR)/,$(SRCS:.c=.o))
CFLAGS	= -Wall -Wextra -Werror -I. -g
NAME	= libftprintf.a

vpath %.c $(SDIR)

all: $(NAME)

main: all
	$(CC) main.c $(NAME)

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
