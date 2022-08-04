# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaile <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 13:39:44 by gsaile            #+#    #+#              #
#    Updated: 2022/08/02 10:36:24 by gsaile           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(wildcard srcs/*.c)
OBJS	= $(SRCS:.c=.o)
CFLAGS	= -Wall -Wextra -Werror
NAME	= bsq

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
