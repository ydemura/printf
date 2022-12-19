//
//  error_check.c
//  ft_printf
//
//  Created by Yuliia Demura on 12/10/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

void	write_error(const char *str)
{
	if (*str == '\0')
	{
		write(1, "Incomplete format specifier", 28);
		return ;
	}
	else
	{
		write(1, "Invalid conversion specifier ", 29);
		write(1, "'", 1);
		write(1, &*str, 1);
		write(1, "'", 1);
	}
}

int		find_arg_(va_list ap_copy, const char str)
{
	char c;
	char *s;
	int n;
	unsigned int d;
	
	if (str == 'c')
	{
		c = va_arg(ap_copy, int);
		if (!c)
			return (0);
	}
	else if (str == 'i' || str == 'd')
	{
		n = va_arg(ap_copy, int);
		if (!n)
			return (0);
	}
	else if (str == 's')
	{
		s = va_arg(ap_copy, char *);
		if (!s)
			return (0);
	}
	else if (str == 'u' || str == 'x' || str == 'X')
	{
		d = va_arg(ap_copy, unsigned int);
		if (!d)
			return (0);
	}
	return (1);
}

int		error_message_for_arg(int n_arg, int n_sign)
{
	if (n_arg != n_sign)
	{
		if (n_arg > n_sign)
			write(1, "Data argument not used by format string", 41);
		else if (n_arg < n_sign)
			write(1, "More '%' conversions than data arguments",40);
		return (-1);
	}
	else
		return (0);
	
}

int		error_check(const char *str)
{
	while (*str != '\0')
	{
		while (*str != '%' && *str != '\0')
			str++;
		if (*str == '%' && *(str + 1) != '\0' && (*(str + 1) == '%' || *(str + 1) == 'c' ||
			*(str + 1) == 's' || *(str + 1) == 'p' || *(str + 1) == 'd' ||
			*(str + 1) == 'i' || *(str + 1) == 'u' || *(str + 1) == 'x' || *(str + 1) == 'X'))
			str += 2;
		else if (*str == '\0')
			return (0);
		else
		{
			write_error(str + 1);
			return (-1);
		}
	}
	return (0);
}


//start of the function with error check:


//int ft_printf(const char *str, ...)
//{
//va_list ap;
//va_list ap_copy;
//int i;
//int n_arg = 0;
//int n_sign = 0;
//
//i = 0;
//va_copy(ap_copy, ap); // all for error check, if arg == valid %
//va_start(ap_copy, str);
//
//while (str[i] != '\0')
//{
//	while (str[i] != '%' && str[i] != '\0')
//		i++;
//	while (str[i] == '%' && str[i + 1] == '%')
//		i += 2;
//	if (str[i] == '%' && str[i + 1] != '%')
//	{
//		i++;
//		n_sign++;
//		if (find_arg_(ap_copy, str[i]) == 1)
//			n_arg++;
//		if (str[i] != '\0')
//			i++;
//	}
//}
//va_end(ap_copy);
//if ((error_check(str) == -1) || (error_message_for_arg(n_arg, n_sign) == -1))
//	return (0);
