/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 21:42:16 by pablo             #+#    #+#             */
/*   Updated: 2020/12/27 19:47:30 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flags
{
	int num;
	int left_just;
	int zero;
	int dot;
	int star;
	int nulldot;
	int zero_cond;
}				t_flags;

int				ft_printf(const char *format, ...);

int				print_char(int c, t_flags flgs);

int				print_int(int n, t_flags flgs);

int				print_unsiged_int(unsigned int n, t_flags flgs);

int				print_string(char *s, t_flags flgs);

int				print_ptr(void *ptr, t_flags flgs);

int				print_hex(unsigned int n, int mayus, t_flags flgs);

char			*ft_print_base_itoa(long int n, int base, int mayus);

void			ft_str_toupper(char *s);

int				num_len(long int n);

int				ft_put_spaces(int len, int is_zero);

int				load_width(char *input, t_flags *flgs);

void			ft_putnbr_unsigned_fd(unsigned int n, int fd);

void			load_ast(t_flags *flgs, int arg);

int				input_loop_aux(char a);

#endif
