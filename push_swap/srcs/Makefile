NAME = pushswap.a

SRC = stack/stack.c \
	  ps/utils.c \
	  ps/operations.c  \
	  ps/algor1.c		\
	  ps/algo100.c	



OBJS =	$(SRC:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror

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
