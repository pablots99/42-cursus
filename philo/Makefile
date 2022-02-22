NAME=philo

SRCS = philo.c \
	   srcs/utils.c \
	   srcs/data.c	\
	   srcs/loops.c

OBJS = $(SRCS:.c=.o)

CC = gcc -g3 -Wall -Wextra -Werror -o $(NAME)

FLAGS = 


all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(FLAGS) $(LIBFLAGS) $(OBJS)


clean:
	rm -f $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
