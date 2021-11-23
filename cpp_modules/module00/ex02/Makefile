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

fclean:
	rm -f $(NAME)
	rm -r $(OBJS)


re:	fclean
	$(NAME)
