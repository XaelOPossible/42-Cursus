NAME = libmaster.a

CFILE_DIR = ./src/

SOURCES = \
		ft_atoi.c ft_itoa.c ft_split.c ft_bzero.c ft_calloc.c ft_strlcpy.c ft_putchar_fd.c ft_putstr_fd.c\
		ft_isdigit.c ft_strdup.c ft_strlen.c ft_strchr.c ft_gnl.c ft_printf.c ft_printhexa_uplow.c\
		ft_printptr.c ft_printuint.c ft_printf_utility.c ft_strjoin.c ft_gnl2.c ft_putnbr_fd\

SRC = $(addprefix $(CFILE_DIR), $(SOURCES))

OBJECTS = $(SRC:.c=.o)

INCLUDE_DIR = ./include/

INCLUDE = libmaster.c

CC = cc

FLAGS = -Wall -Werror -Wextra

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

.c .o:
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re