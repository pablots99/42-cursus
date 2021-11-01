NAME = tests

SRCS = tests.cpp  Account.cpp


OBJS = $(SRCS:.cpp=.o)

CC = clang++

FLAGS = -Wall -Werror -Wextra -std=c++98

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -r $(OBJS)

fclean:	clean
	rm -f $(NAME)


re:	fclean
	$(NAME)
