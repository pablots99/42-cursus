NAME = pushswap.a

SRC = stack.c \
	  utils.c \
	  operations.c 



OBJS =	$(SRC:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror

CC = gcc

all: $(NAME)


$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS) 


fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
