NAME = push_swap

SOURCES = 

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIB_PATH = ./libmaster

LIBFT = $(LIB_PATH)/libmaster.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	cp $(LIBFT) $(NAME)
	$(AR) -rcs $(NAME) $(OBJECTS)

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