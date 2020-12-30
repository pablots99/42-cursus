NAME = minirt

LIBFT = libft/libft.a

SRCS =  main.c 						\
		srcs/rt_file/get_rt_file.c 		\
		srcs/rt_file/parse_rt_file1.c 	\
		srcs/rt_file/parse_rt_file2.c 	\
		srcs/utils/utils.c			\
		srcs/utils/utils2.c			\
		srcs/utils/utils3.c			\
		srcs/utils/ft_atof.c			\
		srcs/utils/utils_free.c			\
		



OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

LFAGS = -L libft -lft  -L minilibx -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LFAGS) $(OBJS) -o $(NAME)

re_libft:
	$(MAKE) fclean -C ./libft
	$(MAKE) bonus -C libft
	$(MAKE) clean -C ./libft

re_minilibx:
	$(MAKE) clean -C ./minilibx	
	$(MAKE)  -C ./minilibx
	$(MAKE) clean -C ./minilibx	
	
clean:
	rm -f *.o
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re : fclean all