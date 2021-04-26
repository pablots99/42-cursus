NAME = pushswap.a

SRC = stack/stack.c 		\
	  stack/stack1.c 		\
	  stack/stack2.c 		\
	  ps/utils.c 			\
	  ps/operations.c  		\
	  ps/algo100.c



OBJS =	$(SRC:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror #-fsanitize=address

CC = gcc

all: $(NAME)


$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJS)

clean:
	/bin/rm -f   ps/*.o
	/bin/rm -f   stack/*.o
	/bin/rm -f  *.o


fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
