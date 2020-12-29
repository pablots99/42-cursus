NAME = minirt

LIBFT = libft/libft.a

SRCS =  main.c 							\
		srcs/rt_file/get_rt_file.c 		\
		srcs/rt_file/parse_rt_file1.c 	\
		srcs/utils/utils.c				\
		srcs/utils/ft_atof.c			\
		srcs/utils/utils2.c			\
		srcs/utils/utils_free.c	



OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LFAGS = -L libft -lft -L minilibx -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C libft
	$(CC) $(CFLAGS) $(LFAGS) $(OBJS) -o $(NAME)

 

clean:
	rm -f *.o
	/bin/rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	$(MAKE) fclean -C ./libft
	/bin/rm -f $(NAME)

re : fclean all