SOURCES = server.c client.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libmaster
LIBFT = $(LIBFT_DIR)/libmaster.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lmaster

all: $(LIBFT) server client

$(LIBFT):
	make -C $(LIBFT_DIR)

server: server.o $(LIBFT)
	$(CC) -o $@ server.o $(LIBFT_FLAGS)

client: client.o $(LIBFT)
	$(CC) -o $@ client.o $(LIBFT_FLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f server client $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
