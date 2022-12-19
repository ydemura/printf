/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 13:29:11 by ydemura       #+#    #+#                 */
/*   Updated: 2020/12/03 13:29:15 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_str(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		len_counter(int n)
{
	int n_check;
	int len;
	
	if (n == 0)
		return (0);

	len = 0;
	n_check = n;
//	if (n < 0)
//	{
//		n_check = -n;
//		len++;
//	}
	while (n_check > 0)
	{
		n_check = n_check / 10;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}

int		find_conversion_specification_format(va_list ap, const char *str, t_format *format, char c)  //25
{
	int len;
	int i;

	i = 0;
	len = 0;
	format->flag = c;
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '-')
			format->flag = '-';
		i++;
	}
	if (str[i] == '*')
		format->field_size = va_arg(ap, int);
	else
	{
		format->field_size = ft_atoi(str + i);
		len = len_counter(format->field_size);
		i = i + len - 1;
	}
	if (format->flag == '-')
		format->field_filler = ' ';
	else if (format->flag == '0')
		format->field_filler = '0';
	return (i + 1);
}

int		find_precision(va_list ap, const char *str, t_format *format, char c) //25
{
	int len;
	int i;

	if (c != '.')
		return (0);
	len = 0;
	i = 0;
	format->precision = '.';
	while (str[i] == '.')
		i++;
	if (str[i] == '*')
		format->precision_size = va_arg(ap, int);
	else
	{
		format->precision_size = ft_atoi(str + i);
		len = len_counter(format->precision_size);
		i += len - 1;
	}
	return (i + 1);
}

void	write_str_before_conv_find_conv(va_list ap, const char *str, t_format *format) //24
{
	while (*str != '\0')
	{
		while (*str != '%' && *str != '\0')
		{
			write(1, &*str, 1);
			str++;
		}
		while (*str == '%' && *(str + 1) == '%')
		{
			write(1, "%", 1);
			str += 2;
		}
		if (*str == '%' && *(str + 1) != '%' && (str + 1) != '\0')
		{
			str++;
			str += find_conversion_specification_format(ap, str, format, *str);
			str += find_precision(ap, str, format, *str);
			find_type(ap, *str, format);
			if (*str != '\0')
				str++;
		}
	}
}

int ft_printf(const char *str, ...)
{
	t_format	format;
	va_list		ap;

	va_start(ap, str);
	write_str_before_conv_find_conv(ap, str, &format);
	va_end(ap);
	return (0);
}
