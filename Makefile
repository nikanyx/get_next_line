# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmachado <cmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 19:30:43 by cmachado          #+#    #+#              #
#    Updated: 2022/09/22 20:54:22 by cmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

VAR = -D BUFFER_SIZE=42

all: $(NAME)

%.o: %.c
	gcc -c $(CFLAGS) $(VAR) $(SRC)

$(NAME): $(OBJ)
	ar -crs -o $(NAME) 

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all