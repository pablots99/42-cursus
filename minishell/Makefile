NAME=minishell

SRCS = minishell.c 

OBJS = $(SRCS:.c=.o)

CC = gcc

LIBFLAGS = -L. libft/libft.a

FLAGS = -Wall -Wextra -Werror -o $(NAME)


all:$(NAME)

$(NAME):$(OBJS)
	$(MAKE) bonus -C ./libft
	$(CC) $(FLAGS) $(LIBFLAGS) $(OBJS)


clean:
	make clean -C libft
	rm -f *.o

fclean: clean
	make fclean -C ./libft
	rm $(NAME)

re: fclean all
