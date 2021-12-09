NAME=philo

SRCS = philo.c \
	   srcs/utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc -g

FLAGS = -Wall -Wextra -Werror  -fsanitize=address   -o $(NAME)


all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(FLAGS) $(LIBFLAGS) $(OBJS)


clean:
	rm -f $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
