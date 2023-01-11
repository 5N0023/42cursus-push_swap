# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 19:19:32 by mlektaib          #+#    #+#              #
#    Updated: 2023/01/11 17:34:08 by mlektaib         ###   ########.fr        #
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

SRCSB =  checker_bonus.c 				\
		bonus/operations_bonus.c	\
		bonus/parsing_bonus.c		\
		bonus/utils1_bonus.c			\
		bonus/utils2_bonus.c			\
		bonus/utils3_bonus.c			\
		bonus/utils4_bonus.c			\
		bonus/utils5_bonus.c			\

BONUS = checker_bonus
NAME = push_swap

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

CC_FLAGS = -Wall -Wextra -Werror

%.o : %.c
	cc -c $< -o $@

$(NAME): $(OBJS) srcs/push_swap.h
	cc  $(OBJS) -o $(NAME)

$(BONUS): $(OBJSB) bonus/push_swap_bonus.h
	cc  $(OBJSB) -o $(BONUS)


all: $(NAME)

bonus : $(BONUS)

clean:
	rm -rf $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY : clean fclean re all