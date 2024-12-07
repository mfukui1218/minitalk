CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
NAME_SERVER = server
NAME_CLIENT = client
LIB_NAME = libminitalk.a

SRC_UTILS = minitalk_utils.c
SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_UTILS = $(SRC_UTILS:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(LIB_NAME) $(NAME_SERVER) $(NAME_CLIENT)

$(LIB_NAME): $(OBJ_UTILS)
	ar rcs $@ $^

$(NAME_SERVER): $(OBJ_SERVER) $(LIB_NAME)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -L. -lminitalk -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIB_NAME)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -L. -lminitalk -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_UTILS) $(OBJ_SERVER) $(OBJ_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(LIB_NAME) $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
