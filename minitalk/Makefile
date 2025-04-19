SRV_SRCS = src/server.c $(FT_PRINTF_SRCS)
CLI_SRCS = src/client.c $(FT_PRINTF_SRCS)
UTILS_SRC = src/utils.c

GCC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_PATH = ./libmaster
LIBFT = $(LIB_PATH)/libmaster.a

SRV_OBJS = $(SRV_SRCS:.c=.o)
CLI_OBJS = $(CLI_SRCS:.c=.o)
UTILS_OBJS = $(UTILS_SRC:.c=.o)

RM = rm -f

SRV_NAME = server
CLI_NAME = client

all: $(LIBFT) $(SRV_NAME) $(CLI_NAME)

$(LIBFT):
	make -C $(LIB_PATH) all

$(SRV_NAME): $(LIBFT) $(SRV_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) $(SRV_OBJS) $(UTILS_OBJS) -L$(LIB_PATH) -lmaster -o $(SRV_NAME)

$(CLI_NAME): $(LIBFT) $(CLI_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) $(CLI_OBJS) $(UTILS_OBJS) -L$(LIB_PATH) -lmaster -o $(CLI_NAME)

%.o: %.c
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRV_OBJS) $(CLI_OBJS) $(UTILS_OBJS)
	make -C $(LIB_PATH) clean

fclean: clean
	$(RM) $(SRV_NAME) $(CLI_NAME)
	make -C $(LIB_PATH) fclean

re: fclean all
