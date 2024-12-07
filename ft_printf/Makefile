# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 13:07:16 by mfukui            #+#    #+#              #
#    Updated: 2023/10/03 17:38:41 by mfukui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_memset.c  ft_putchar.c ft_putchar_c.c ft_putnbr.c ft_putp_c.c ft_putstr_c.c  ft_putu_c.c ft_putsx_c.c ft_putlx_c.c ft_printf.c ft_num_len.c


OBJ = $(SRC:.c=.o)
TARGET = libftprintf.a

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rcs $@ $^

%.o: %.c printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re