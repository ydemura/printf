/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 13:28:58 by ydemura       #+#    #+#                 */
/*   Updated: 2020/12/03 13:29:17 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_printf_h
#define ft_printf_h

#include <stdio.h>

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct		s_format
{
	char			flag;
	int				field_size;
	char			field_filler;
	char			precision;
	int				precision_size;
	char			precision_filler;
	char			*string;
}					t_format;

//ft_printf.c
int ft_printf(const char *, ...);
void	write_str(char *str);

//find_type_and_write
char	*apply_flag(t_format *format);
void	find_type(va_list ap, const char str, t_format *format);
void	i_write(va_list ap, t_format *format);
//void	c_write(va_list ap, t_format *format);
//void	d_write(va_list ap, t_format *format);
//void	s_write(va_list ap, t_format *format);
//void	p_write(va_list ap, t_format *format);


// error_check.c
void	write_error(const char *str);
int		error_check(const char *str);
int		find_arg_(va_list ap_copy, const char str);
int		error_message_for_arg(int n_arg, int n_sign);

#endif /* ft_printf_h */



// Plan

// 1. call argument va_start

// 2. check what is that argument (check the string I receive)

// 3. write result depending on the type of arg

// 4. va_arg -> move to the next one

// 5. va_end
