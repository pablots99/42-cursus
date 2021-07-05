NAME=minishell

SRCS =	minishell.c 					\
		srcs/parser/recive_comands.c	\
		srcs/parser/parse_comands.c		\
		srcs/execution/execute_command.c
OBJS = $(SRCS:.c=.o)

CC = gcc -g3

LIBFLAGS = -L. libft/libft.a

FLAGS = -Wall -Wextra -Werror -lreadline    -o $(NAME)


all:$(NAME)

$(NAME):$(OBJS)
	$(MAKE) bonus -C ./libft
	$(CC) $(FLAGS) $(LIBFLAGS) $(OBJS)


clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm $(NAME)

re: fclean all
