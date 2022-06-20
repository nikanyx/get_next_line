# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 19:30:43 by cmachado          #+#    #+#              #
#    Updated: 2022/06/06 21:08:43 by cmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

CFLAGS = -Wall -Werror -Wextra

VAR = -D BUFFER_SIZE=10

all: $(NAME) clean

test:
	gcc $(CFLAGS) $(VAR) $(SRC)

object:
	gcc -c $(CFLAGS) $(VAR) $(SRC)

$(NAME): object
	ar -crs $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all