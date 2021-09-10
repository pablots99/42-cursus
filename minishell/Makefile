NAME=minishell

SRCS =	minishell.c 						\
		srcs/parser/parse_comands.c			\
		srcs/parser/tokens.c				\
		srcs/parser/parse_aux.c				\
		srcs/parser/parse_aux2.c				\
		srcs/execution/execute_command.c	\
		srcs/execution/execute_command_aux.c	\
		srcs/execution/signal__handler.c 	\
		srcs/builtins/env.c					\
		srcs/builtins/pwd_cd.c				\
		srcs/builtins/echo.c				\
		srcs/builtins/export.c				\
		srcs/builtins/exit.c				\
		srcs/builtins/unset.c				\
		srcs/builtins/session_vars.c		\
		srcs/utils/utils.c
OBJS = $(SRCS:.c=.o)

CC = gcc -Wall -Werror -Wextra -g

#campues
# export LDFLAGS="-L/Users/ptorres/.brew/opt/readline/lib"; export CPPFLAGS="-I/Users/ptorres/.brew/opt/readline/include"
LIBFLAGS = -L. libft/libft.a -L/Users/ptorres/.brew/opt/readline/lib -I/Users/ptorres/.brew/opt/readline/include


#mac
# export LDFLAGS="-L/usr/local/opt/readline/lib" ; export CPPFLAGS="-I/usr/local/opt/readline/include"
#LIBFLAGS = -L. libft/libft.a -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include


#-fsanitize=address


FLAGS = -lreadline -fsanitize=address   -o $(NAME)


all:$(NAME)


$(NAME):$(OBJS)
	export LDFLAGS="-L/Users/ptorres/.brew/opt/readline/lib"; export CPPFLAGS="-I/Users/ptorres/.brew/opt/readline/include"
	$(MAKE) bonus -C ./libft
	$(CC) $(FLAGS) $(LIBFLAGS) $(OBJS)


clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm $(NAME)

re: fclean all
