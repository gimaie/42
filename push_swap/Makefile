NAME = push_swap

cc = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	error.c error2.c general_push_swap.c index.c \
		make_list_and_stack.c rarbrr.c rrarrbrrr.c sapa.c sort.c \
		sortfive.c sort_turk_ver.c swap_push.c \
		turk_calculate_move_cost.c turk_cost_pattern.c \
		turk_find_optimal_insert_pos_in_b.c turk_push_all_to_a.c \
		turk_push_all_to_b.c utils.c

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
