NAME=pipex

SRCS =	pipex.c 					\
		srcs/utils.c				\
			srcs/utils2.c				\
				srcs/utils3.c				\
		srcs/ft_split.c
OBJS = $(SRCS:.c=.o)

CC = gcc -g
#-fsanitize=address

FLAGS = -Wall -Wextra -Werror  -fsanitize=address  -o $(NAME)


all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(FLAGS)  $(OBJS)


clean:
	rm -f $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
