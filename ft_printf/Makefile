NAME = libftprintf.a

LIBFT = libft/libft.a

SRCS = 	ft_printf.c 				\
		srcs/ft_print_base_itoa.c	\
		srcs/ft_print_ptr.c			\
		srcs/ft_printf_char.c 		\
		srcs/ft_printf_hex.c		\
		srcs/ft_printf_int.c		\
		srcs/ft_printf_string.c		\
		srcs/ft_printf_unsigned.c		\
		srcs/ft_printf_utils.c		\
		srcs/ft_loadflags.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(SRCS) 
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f *.o
	/bin/rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	$(MAKE) fclean -C ./libft
	/bin/rm -f $(NAME)

re : fclean all