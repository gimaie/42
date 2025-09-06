NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC			= ft_printf.c ft_deal.c ft_deal2.c utils.c utils2.c
OBJ 	= $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
