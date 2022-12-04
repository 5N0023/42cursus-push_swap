# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 20:07:38 by mlektaib          #+#    #+#              #
#    Updated: 2022/12/03 15:37:14 by mlektaib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_isalpha.c 	\
	   ft_isdigit.c		\
	   ft_isalnum.c		\
	   ft_isascii.c		\
	   ft_isprint.c		\
	   ft_strlen.c		\
	   ft_memset.c		\
	   ft_bzero.c		\
	   ft_memcpy.c		\
	   ft_memmove.c		\
	   ft_strlcpy.c		\
	   ft_strlcat.c		\
	   ft_toupper.c		\
	   ft_tolower.c		\
	   ft_strrchr.c		\
	   ft_strncmp.c		\
	   ft_memchr.c		\
	   ft_memcmp.c		\
	   ft_strnstr.c		\
	   ft_atoi.c		\
	   ft_calloc.c		\
	   ft_strdup.c		\
	   ft_substr.c		\
	   ft_strjoin.c		\
	   ft_strtrim.c		\
	   ft_split.c		\
	   ft_itoa.c		\
	   ft_strmapi.c		\
	   ft_striteri.c	\
	   ft_putchar_fd.c	\
	   ft_putstr_fd.c	\
	   ft_putendl_fd.c	\
	   ft_putnbr_fd.c	\
	   ft_strchr.c		\
	   ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c 		\
		get_next_line.c

NAME = libft.a


OBJS = $(SRCS:.c=.o)

CC_FLAGS = -Wall -Wextra -Werror

%.o : %.c libft.h
	cc $(CC_FLAGS) -c $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) 

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re all