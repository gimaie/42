NAME = pipex

cc = cc
CFLAGS = -Wall -Wextra -Werror

SRC = execve.c  pipex_general.c  split1.c  split2.c  split_free_joincmp.c  when_error.c  utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
