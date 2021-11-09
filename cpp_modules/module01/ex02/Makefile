NAME = HITHISISBRAIN

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)


CC = clang++

FLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -r $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean
	$(NAME)

