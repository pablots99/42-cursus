NAME=libasm.a


SRCS = srcs/ft_strlen.s	\
		 srcs/ft_strcpy.s \
		 srcs/ft_strcmp.s\
		 srcs/ft_strdup.s \
		  srcs/ft_write.s

OBJS = ${SRCS:.s=.o}


CC = nasm

FLAGS =  -f macho64

all: ${NAME}

${NAME}:
	${CC} ${FLAGS} srcs/ft_strlen.s
	${CC} ${FLAGS} srcs/ft_strcpy.s
	${CC} ${FLAGS} srcs/ft_strcmp.s
	${CC} ${FLAGS} srcs/ft_strdup.s
	ar rc ${NAME} ${OBJS}

clean:
	/bin/rm -f $(OBJS)


fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
