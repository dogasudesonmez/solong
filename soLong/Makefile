NAME = solong

MINILIBX_DIR = minilibx-linux
PRINTF_DIR = printf
LIBFT_DIR = libft

PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

SOURCES = check_map.c image_checkers.c moves.c place_images_game.c place_images_window.c read_map.c get_next_line.c main.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz


all:  $(MINILIBX) $(LIBFT) $(PRINTF) $(GETNEXTLINE) $(NAME)

$(MINILIBX):
	make -C $(MINILIBX_DIR)
$(LIBFT):
	make -C $(LIBFT_DIR)
$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJECTS) $(MINILIBX) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	rm -f $(OBJECTS) $(BOBJECTS)
	make clean -C $(MINILIBX_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(MINILIBX_DIR)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re