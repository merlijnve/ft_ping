# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/07/19 11:58:17 by mvan-eng      #+#    #+#                  #
#    Updated: 2022/01/11 13:05:52 by merlijn       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

HEADER_FILE = ft_ping.h
NAME	= ft_ping

SRC	=	main.c
OBJ	= $(SRC:.c=.o)

GCC		= clang
FLAGS	= -Wall -Wextra -Werror

LIB	= libft/libft.a

all:	$(NAME)

$(NAME): 	$(SRC)
	@echo "Making libft..."
	@cd libft && make
	@echo "Making ft_ping..."
	$(GCC) $(FLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	@echo "Cleaning ft_ping..."
	rm -f $(OBJS)
	@echo "Cleaning libft..."
	@cd libft && make clean

fclean: clean
	@echo "FCleaning ft_ping..."
	rm -f $(NAME)
	@echo "FCleaning libft..."
	@cd libft && make fclean

re: fclean all

.PHONY:	clean fclean re
