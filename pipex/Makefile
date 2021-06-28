NAME=pipex

SRCS =	pipex.c 					\
		srcs/utils.c				\
		srcs/ft_split.c
OBJS = $(SRCS:.c=.o)

CC = gcc -g3


FLAGS = -Wall -Wextra -Werror  -fsanitize=address   -o $(NAME)


all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(FLAGS)  $(OBJS)


clean:
	rm -f $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
