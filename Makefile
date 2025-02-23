NAME = solong

MINILIBX_DIR = minilibx
PRINTF_DIR = printf
LIBFT_DIR = libft

PRINTF = $(PRINTF_DIR)/libftprintf.a
GETNEXTLINE = $(GETNEXTLINE_DIR)
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

SOURCES = $(GETNEXTLINE)/get_next_line_bonus.c $(GETNEXTLINE)/get_next_line_utils_bonus.c $(GETNEXTLINE)/get_next_line.c $(GETNEXTLINE)/get_next_line_utils.c read_map.c window.c check_map.c

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
	$(CC) $(CFLAGS) $(MINILIBX) $(LIBFT) $(PRINTF) $(OBJECTS) -o $(NAME)

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