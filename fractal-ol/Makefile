NAME = fractaol

LIBFT = libft/libft.a

SRCS = fractal.c \
	   srcs/utils/mlx_utils.c \
	   srcs/utils/colors.c


OBJS = $(SRCS:.c=.o)

CC = gcc

#-fsanitize=address
CFLAGS = -g   #-Wall -Wextra -Werror


LFAGS = -L. ./libft/libft.a   libmlx.dylib -framework Metal -framework AppKit


all: $(NAME)



$(NAME):$(OBJS)
	$(CC)    $(CFLAGS)   $(LFAGS) $(SRCS) -o $(NAME)


re_libft:
	$(MAKE) fclean -C ./libft
	$(MAKE) bonus -C libft
	$(MAKE) clean -C ./libft

re_minilibx:
	$(MAKE) clean -C ./minilibx
	$(MAKE)  -C ./minilibx
	rm -f ./minilibx/*.o
	mv minilibx/libmlx.dylib .

clean:
	rm -f *.o
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re : fclean all

install :re_minilibx  re_libft
