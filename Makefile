# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 19:19:32 by mlektaib          #+#    #+#              #
#    Updated: 2023/01/10 20:26:33 by mlektaib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c 				\
		./srcs/operations.c 		\
		./srcs/findpos.c			\
		./srcs/lis1.c 				\
		./srcs/lis2.c 				\
		./srcs/longsort.c			\
		./srcs/parsing.c			\
		./srcs/rotatetopusha.c 	\
		./srcs/shortsort.c			\
		./srcs/utils1.c 			\
		./srcs/utils2.c 			\
		./srcs/utils3.c 			\
		./srcs/utils4.c 			\
		./srcs/utils5.c 			\

NAME = push_swap

OBJS = $(SRCS:.c=.o)

CC_FLAGS = -Wall -Wextra -Werror

%.o : %.c push_swap.h
	cc -c $< -o $^

$(NAME): $(OBJS)
	mkdir objs
	cc  $(OBJS) -o $(NAME)

all: $(NAME)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re all