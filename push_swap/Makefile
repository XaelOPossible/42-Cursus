NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src/
LIB_PATH = ./libmaster
LIBFT = $(LIB_PATH)/libmaster.a

C_FILE = misc.c check_params.c push_swap.c push.c \
			r_rotate.c rotate.c swap.c initialize.c \
			list_link.c sort_utils.c sorting.c chunck_sort.c \

SRC = $(addprefix $(SRC_DIR), $(C_FILE))
OBJECTS = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIB_PATH) all

%.o: %.c
	$(CC) -c $(CFLAGS) -I ./ $< -o $@

clean:
	rm -f $(OBJECTS)
	make -C $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
