NAME = libftprintf.a

SOURCES = \
		ft_print_hexadecimal.c ft_printhexa_uplow.c ft_printf_utility.c \
		ft_printuint.c ft_printf.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all