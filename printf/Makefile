NAME = libftprintf.a

SOURCES = ft_printptr.c ft_printf_utility.c ft_printf.c \
		ft_printhexa_uplow.c ft_printuint.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIB_PATH = ./libft

LIBFT = $(LIB_PATH)/libft.a

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
