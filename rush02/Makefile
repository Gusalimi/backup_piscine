# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaile <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 09:38:42 by gsaile            #+#    #+#              #
#    Updated: 2022/07/30 11:26:13 by gsaile           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_DIR	= includes

SRC_DIR	= srcs
SRCS	= $(wildcard $(SRC_DIR)/*.c)
OBJS	= $(SRCS:.c=.o)
NAME	= rush-02

LIB_DIR		= lib
LIB_SRCS	= $(wildcard $(LIB_DIR)/*.c)
LIB_OBJS	= $(LIB_SRCS:.c=.o)
LIB_NAME	= $(LIB_DIR)/libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $(<:.c=.o)

all:			$(LIB_NAME) $(NAME)

$(NAME):		$(OBJS)
	$(CC) $(CFLAGS) -I $(INC_DIR) -L $(LIB_DIR) -lft $(OBJS) -o $(NAME)

$(LIB_NAME):	$(LIB_OBJS)
	ar rc $(LIB_NAME) $(LIB_OBJS)
	ranlib $(LIB_NAME)

lib:			$(LIB_NAME)

clean:
	$(RM) $(OBJS) $(LIB_OBJS)

fclean:			clean
	$(RM) $(NAME) $(LIB_NAME)

re:				fclean all

.PHONY:	lib all clean fclean re
