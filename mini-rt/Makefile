NAME = minirt

LIBFT = libft/libft.a

SRCS =  main.c 						\
		srcs/parse/get_rt_file.c 		\
		srcs/parse/parse_rt_file1.c 	\
		srcs/parse/parse_rt_file2.c 	\
		srcs/utils/utils.c				\
		srcs/utils/utils2.c				\
		srcs/utils/utils3.c				\
		srcs/utils/colors.c				\
		srcs/utils/keys.c				\
		srcs/utils/mlx_utils.c				\
		srcs/utils/ft_atof.c			\
		srcs/utils/utils_free.c			\
		srcs/math/vectors.c				\
		srcs/raytracing/cast_rays.c		\
		srcs/raytracing/sphere.c		\
		srcs/raytracing/plane.c			\
		srcs/raytracing/cylinder.c		\
		srcs/raytracing/square.c		\
		srcs/raytracing/triangle.c		\
		srcs/raytracing/shading.c		

		



OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

LFAGS = -L libft -lft   libmlx.dylib -framework Metal -framework AppKit


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -g $(LFAGS) $(OBJS) -o $(NAME)
	make clean

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


install : re_libft re_minilibx re