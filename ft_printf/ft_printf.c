/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:18:22 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/01 08:26:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Make a printf function
* This function will take a string and a list of arguments
* and print them to the standard output.
* It will return the number of characters printed.
*/

int	ft_printf_arg(const char c, t_ft_printf *t_printf)
{
	if (c == 'c')
		t_printf->chars_printed += ft_print_char(va_arg(t_printf->args, int));
	else if (c == 's')
		t_printf->chars_printed += ft_print_str(va_arg(t_printf->args, char *));
	else if (c == 'd' || c == 'i')
		t_printf->chars_printed += ft_print_num(va_arg(t_printf->args, int));
	else if (c == 'u')
		t_printf->chars_printed += ft_print_uns(va_arg(t_printf->args, \
		unsigned int));
	else if (c == 'x' || c == 'X')
		t_printf->chars_printed += ft_print_hex(va_arg(t_printf->args, \
		unsigned int), &c);
	else if (c == 'p')
		t_printf->chars_printed += ft_print_adrr(va_arg(t_printf->args, \
		unsigned long int));
	else if (c == '%')
		t_printf->chars_printed += ft_print_char('%');
	else
		t_printf->chars_printed += ft_print_char(c);
	return (t_printf->chars_printed);
}

int	ft_printf(const char *format, ...)
{
	t_ft_printf	t_printf;

	t_printf.chars_printed = 0;
	va_start(t_printf.args, format);
	while (*format != '\0')
	{
		if (*format != '%')
			t_printf.chars_printed += ft_print_char(*format);
		if (*format == '%')
		{
			format++;
			ft_printf_arg(*format, &t_printf);
		}
		format++;
	}
	va_end(t_printf.args);
	return (t_printf.chars_printed);
}
