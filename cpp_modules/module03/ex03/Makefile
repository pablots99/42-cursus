NAME = DiamonTrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp  DiamondTrap.cpp


OBJ = $(SRCS:.cpp=.o)
CPP = clang++
CPP_FLAGS = -Wall -Wextra -Werror --std=c++98

all: $(NAME)

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CPP) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

