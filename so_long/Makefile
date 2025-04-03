NAME = so_long

CC = gcc

FLAG = -Wall -Werror -Wextra

LIBMASTER_PATH = ./libmaster/

LIBMASTER_FILE = libmaster.a

MLX_FILE = libmlx.a

LIBMASTER_LIB = $(addprefix $(LIBMASTER_PATH), $(LIBMASTER_FILE))

MLX_FLAG = -lX11 -lXext

MLX_PATH = ./minilibx-linux/

MLX_LIB = $(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX = $(MLX_LIB) $(MLX_FLAG)

SRC_DIR = ./core/

INC_DIR = ./include/

C_FILE =   map_checker.c render.c set_keymove.c	set.c \
				texture.c utils.c map.c map_checker2.c \

SRC	= $(addprefix $(SRC_DIR), $(C_FILE))

OBJ = $(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

lib:
	@make -C $(LIBMASTER_PATH)

mlx:
	@make -sC $(MLX_PATH)

$(NAME): lib mlx $(OBJ)
	$(CC) $(OBJ) $(LIBMASTER_LIB) $(MLX_EX) -o $(NAME)

clean:
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBMASTER_PATH)
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME)
	@make fclean -C $(LIBMASTER_PATH)

re: fclean all

.PHONY: all clean fclean re
