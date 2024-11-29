NAME = libftprintf.a

SOURCES = \
		Libft/ft_strlen.c Libft/ft_putchar_fd.c Libft/ft_itoa.c Libft/ft_strdup.c \
		ft_print_hexadecimal.c ft_printf_utility.c ft_printf.c \
		ft_printhexa_uplow.c ft_printuint.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
