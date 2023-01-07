SRCS =	main.c \
		operations.c

NAME = push_swap

OBJS = $(SRCS:.c=.o)

CC_FLAGS = -Wall -Wextra -Werror

%.o : %.c push_swap.h
	cc -c $<

$(NAME): $(OBJS)
	cc  $(OBJS) ./libft/libft.a -o $(NAME)

all: $(NAME)



clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re all