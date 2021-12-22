# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/07/19 11:58:17 by mvan-eng       #+#    #+#                 #
#    Updated: 2019/10/15 14:33:42 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

HEADER_FILE = ft_ping.h
NAME	= ft_ping

SRCS	=	main.c
OBJS	= $(SRCS:.c=.o)

GCC		= gcc
FLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	$(GCC) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADER_FILE)
	$(GCC) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	clean fclean re
