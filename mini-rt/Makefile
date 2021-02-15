NAME = minirt

LIBFT = libft/libft.a

SRCS =  main.c 								\
		srcs/parse/get_rt_file.c 			\
		srcs/parse/parse_rt_file1.c 		\
		srcs/parse/parse_rt_file2.c 		\
		srcs/parse/parse_rt_file3.c 		\
		srcs/parse/parse_rt_file4.c 		\
		srcs/parse/parse_rt_no_bonus.c		\
		srcs/parse/parse_rt_file2_no_bonus.c		\
		srcs/utils/utils.c					\
		srcs/utils/utils2.c					\
		srcs/utils/utils3.c					\
		srcs/utils/colors.c					\
		srcs/utils/keys.c					\
		srcs/utils/mlx_utils.c				\
		srcs/utils/bmp_img.c				\
		srcs/utils/ft_atof.c				\
		srcs/utils/utils_free.c				\
		srcs/math/vectors.c					\
		srcs/math/vectors1.c				\
		srcs/math/vectors2.c				\
		srcs/math/vectors3.c				\
		srcs/math/utils.c					\
		srcs/raytracing/cast_rays.c			\
		srcs/objects/sphere.c				\
		srcs/objects/camera.c				\
		srcs/objects/plane.c				\
		srcs/objects/cylinder.c				\
		srcs/objects/cylinder2.c			\
		srcs/objects/square.c				\
		srcs/objects/ligth.c				\
		srcs/objects/triangle.c				\
		srcs/objects/cube.c					\
		srcs/objects/pyramid.c				\
		srcs/raytracing/shading.c			\
		srcs/raytracing/paint_scene.c		\
		srcs/raytracing/intersections.c		\
		srcs/raytracing/intersections1.c	
	

	

		



OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS:.c=.o)
CC = gcc

#-fsanitize=address 
CFLAGS = -D BONUS=0   -g   -Wall -Wextra -Werror 

CFLAGS_BONUS = -D BONUS=1 -g   -Wall -Wextra -Werror 

LFAGS = -L libft -lft   libmlx.dylib -framework Metal -framework AppKit


all: $(NAME)



bonus:$(OBJS)
	 $(CC)    $(CFLAGS_BONUS) $(LFAGS) $(SRCS) -o $(NAME) 


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


install : re_libft re_minilibx re