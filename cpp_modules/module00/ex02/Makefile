NAME = phonebook

SRCS = srcs/Account.cpp		\
	   srcs/tests.cpp


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

{"auth":{"uid":"114701549","role":"user","token":{"role":"user","exp":1632396445,"iat":1632310045,"sub":"114701549","aud":"mth-mrgreen","auth_time":1632310045,"iss":"https://securetoken.google.com/mth-mrgreen"}},"expires":1632396445,"token":"eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJ2IjowLCJkIjp7InVpZCI6IjExNDcwMTU0OSIsInJvbGUiOiJ1c2VyIn0sImlhdCI6MTYzMjMxMDA0NX0.jg4Mz0zZ2eGcDfZTz_OrnCxVUDedb98YtgOzF6lce7k","uid":"114701549","provider":"custom"}
{"gameIndex":-1,"category":null,"scrolled":0,"context":null}
