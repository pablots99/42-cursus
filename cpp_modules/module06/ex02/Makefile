NAME = main

SRCS = main.cpp imp/Base.cpp  imp/A.cpp imp/B.cpp imp/C.cpp  imp/utils.cpp

OBJ = $(SRCS:.cpp=.o)
CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror --std=c++98

all: $(NAME)

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
