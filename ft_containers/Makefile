NAME = containers

SRCS = main.cpp

OBJ = $(SRCS:.cpp=.o)
CPP = c++
CPP_FLAGS = --std=c++98 -g3

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
