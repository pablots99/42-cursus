NAME=minishell

SRCS =	minishell.c 						\
		srcs/parser/recive_comands.c		\
		srcs/parser/parse_comands.c			\
		srcs/parser/split_ms.c			\
		srcs/execution/execute_command.c	\
		srcs/builtins/env.c				\
		srcs/builtins/pwd_cd.c				\
		srcs/builtins/echo.c				\
		srcs/utils/utils.c
OBJS = $(SRCS:.c=.o)

CC = gcc -g

LIBFLAGS = -L. libft/libft.a -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include

FLAGS = -Wall -Wextra -Werror -lreadline   -o $(NAME)


all:$(NAME)

# export LDFLAGS="-L/usr/local/opt/readline/lib"
#   	export CPPFLAGS="-I/usr/local/opt/readline/include"

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
