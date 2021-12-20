NAME = FragTrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp FragTrap.hpp

OBJS = $(SRCS:.cpp=.o)
CC = clang++

FLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -r $(OBJS)

fclean:
	rm -f $(NAME)
	rm -r $(OBJS)

re:	fclean all


