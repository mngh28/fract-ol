NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = \
	main.c burning_ship.c colorchange.c helpers.c image.c julia.c mandelbrot.c \
	msg.c pallet1.c pallet2.c pallet3.c parsing.c render.c zoommove.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

INCLUDES = -I. -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDES) $(LIBS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all: $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
