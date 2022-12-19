//
//  find_type_and_write.c
//  ft_printf
//
//  Created by Yuliia Demura on 12/12/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//

#include "ft_printf.h"
#include "libft.h"

void	*ft_memcpy_from_end(void *restrict dst, const void *restrict src, size_t n) //24
{
	unsigned	int		len_s;
	unsigned	int		len_d;
	unsigned	int		i;
	unsigned	char	*destination;
	unsigned	char	*sorce;

	i = 0;
	destination = (unsigned char *)dst;
	sorce = (unsigned char *)src;
	len_d = ft_strlen((const char *)dst) - 1;
	len_s = ft_strlen((const char *)src) - 1;
	if (len_s < len_d)
	{
		while (i < n && (dst != (void *)0 || src != (void *)0))
		{
			destination[len_d] = sorce[len_s];
			i++;
			len_s--;
			len_d--;
		}
	}
	return (dst);
}

char	*create_string_using_flag(t_format *format)
{
	char *new_string;
	int i;

	i = 0;
	new_string = NULL;
	if (format->flag == '-' || format->flag == '0')
	{
		new_string = malloc((format->field_size + 1) * sizeof(char));
		while (i < format->field_size)
		{
			new_string[i] = format->field_filler;
			i++;
		}
		new_string[i] = '\0';
	}
	
	return (new_string);
}

char	*apply_precision(t_format *format, char *string)
{
	int i;
	
	i = 0;
	if (format->flag == '0')
	{
		format->precision_filler = ' ';
	}
	else if (format->flag == '-')
	{
		//here
	}
	while (i < format->field_size - format->precision_size)
	{
		string[i] = format->precision_filler;
		i++;
	}
	return (0);
}

void	format_field_with_precision()
{
	
}


void	i_write(va_list ap, t_format *format)
{
	int n;
	char *s;
	char *string;

	n = va_arg(ap, int);
	s = ft_itoa(n);
	string = create_string_using_flag(format);
	if (ft_strlen(s) < ft_strlen(string))
	{
		if (format->flag == '-')
			ft_memcpy(string, s, ft_strlen(s));
		else if (format->flag == '0')
			ft_memcpy_from_end(string, s, ft_strlen(s));
		write_str(string);
	}
	else if (format->precision == '.')
	{
		// here I need to add 0 as many as precision_size is
	}
	else
	{
		write_str(s);
	}
	if (s != NULL)
	free(s);
	free(string);
}

void	find_type(va_list ap, const char str, t_format *format)
{
	if (str == 'i')
		i_write(ap, format);
//	else if (str == 'c')
	//		c_write(ap, format);
//	else if (str == 'd')
//		d_write(ap, format);
//	else if (str == 's')
//		s_write(ap, format);
//	else if (str == 'p')
//		p_write(ap, format);
}


//char	*apply_flag(t_format *format)
//{
//	char *new_string;
//	int i;
//
//	i = 0;
//	new_string = NULL;
//	if (format->flag == '-' || format->flag == '0')
//	{
//		new_string = malloc((format->field_size + 1) * sizeof(char));
//		while (i < format->field_size)
//		{
//			new_string[i] = format->field_filler;
//			i++;
//		}
//		new_string[i] = '\0';
//	}
//	return (new_string);
//}
//
//char	*apply_precision(t_format *format, char *string)
//{
//	int i;
//	char *new_string;
//
//	i = 0;
//	if (format->flag == '0')
//	{
//		while (i < format->field_size - format->precision_size)
//		{
//			string[i] = ' ';
//			i++;
//		}
//	}
//	else if (format->flag == '-')
//	{
//		//here
//	}
//	else
//	{
//		new_string = malloc((format->precision_size + ft_strlen(string) + 1) * sizeof(char));
//		while (i < format->precision_size)
//		{
//			new_string[i] = '0';
//			i++;
//		}
//		ft_memcpy_from_end(new_string, string, ft_strlen(string));
//		new_string[(format->precision_size + ft_strlen(string))] = '\0';
//		free(string);
//		string = NULL;
//		return(new_string);
//	}
//	return (0);
//}
//
//
//void	i_write(va_list ap, t_format *format)
//{
//	int n;
//	char *s;
//	char *string;
//
//	n = va_arg(ap, int);
//	s = ft_itoa(n);
//	string = apply_flag(format);
//	if (ft_strlen(s) < ft_strlen(string))
//	{
//		if (format->flag == '-')
//			ft_memcpy(string, s, ft_strlen(s));
//		else if (format->flag == '0')
//			ft_memcpy_from_end(string, s, ft_strlen(s));
//		if (format->precision == '.')
//			apply_precision(format, string);
//		write_str(string);
//	}
//	else
//	{
//		if (format->precision == '.')
//			s = apply_precision(format, s);
//		write_str(s);
//	}
//	if (s != NULL)
//		free(s);
//	free(string);
//}




//void	c_write(va_list ap, t_format *format)
//{
//	char c;
//
//	c = va_arg(ap, int);
//	write(1, &c, 1);
//	return ;
//
//}
//
//void	d_write(va_list ap, t_format *format)
//{
//	int n;
//	char *s;
//
//	n = va_arg(ap, int);
//	s = ft_itoa(n);
//	write_str(s);
//	free(s);
//}
//void	s_write(va_list ap, t_format *format)
//{
//	char *s;
//
//	s = va_arg(ap, char *);
//	write_str(s);
//}
//
//void	p_write(va_list ap, t_format *format)
//{
//	unsigned long long ptr;
//	void *s1;
//
//	s1 = va_arg(ap, void *);
//	ptr = (unsigned long long) s1;
//		// I need itoa that will handle long long + hexadesimal set T_T
//}
