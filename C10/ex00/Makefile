# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaile <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 18:23:41 by gsaile            #+#    #+#              #
#    Updated: 2022/07/28 18:23:45 by gsaile           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		= srcs
INC_DIR		= includes
SRCS		= $(SRC_DIR)/main.c
OBJS		= $(SRCS:.c=.o)
LIB_DIR		= lib
LIB_SRCS	= $(wildcard $(LIB_DIR)/*.c)
LIB_OBJS	= $(LIB_SRCS:.c=.o)
LIB_NAME	= $(LIB_DIR)/libft.a
NAME		= ft_display_file
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

.c.o:
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB_NAME)
	$(CC) $(CFLAGS) -I $(INC_DIR) -L $(LIB_DIR) -lft $(OBJS) -o $(NAME)

$(LIB_NAME): $(LIB_OBJS)
	ar rc $(LIB_NAME) $(LIB_OBJS)
	ranlib $(LIB_NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
