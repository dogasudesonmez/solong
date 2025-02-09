NAME = solong

MINILIBX_DIR = minilibx
PRINTF_DIR = printf
LIBFT_DIR = libft

PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

SOURCES = ./getnextline/get_next_line_bonus.c ./getnextline/get_next_line_utils_bonus.c /
./getnextline/get_next_line.c ./getnextline/get_next_line_utils.c 

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror


all:  $(MINILIBX) $(LIBFT) $(PRINTF) $(NAME)

$(MINILIBX):
	make -C $(MINILIBX_DIR)
$(LIBFT):
	make -C $(LIBFT_DIR)
$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MINILIBX) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	rm -f $(OBJECTS) $(BOBJECTS)
	make clean -C $(MINILIBX_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(MINILIBX_DIR)
	make flcean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re