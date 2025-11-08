NAME = so_long


CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC = sources/main.c \
      sources/error.c \
      sources/utils.c \
      sources/validate_map.c \
      sources/validate_map2.c \
      sources/validate_map3.c \
      sources/mlx1.c\
      sources/hooks.c\
	  sources/button.c\
      sources/graphics.c\
      get_next_line/get_next_line_bonus.c \
      get_next_line/get_next_line_utils_bonus.c


OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

PRINTF = ft_printf/ft_printf.a

MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm


# --- ルール定義 ---

# デフォルトルール (makeとだけ打った時に実行される)
all: $(NAME)

# 実行ファイルを作成するルール
# $(OBJ)と各ライブラリをリンクし、MiniLibXのフラグも追加する
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAGS)

# libft.a を作成するルール
$(LIBFT):
	make bonus -C libft

$(PRINTF):
	make -C ft_printf

# オブジェクトファイルを削除するルール
clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C ft_printf clean

# オブジェクトファイルと実行ファイルを削除するルール
fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C ft_printf fclean

# 全てクリーンにしてから再コンパイルするルール
re: fclean all

# 偽のターゲットを指定
.PHONY: all clean fclean re 
