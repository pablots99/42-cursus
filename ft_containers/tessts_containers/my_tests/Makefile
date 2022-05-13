NAME = containers

SRCS = main.cpp

OBJ = $(SRCS:.cpp=.o)
CPP = clang++
CPP_FLAGS =  -g3 --std=c++98

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
