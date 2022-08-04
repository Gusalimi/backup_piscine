INC_DIR = includes
SRC_DIR = srcs
SRCS	= $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_swap.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strcmp.c
NAME	= libft.a
OBJS	= $(SRCS:.c=.o)
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
