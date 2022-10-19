/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:31:45 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/23 04:40:26 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hex_process(unsigned int n, const char *c)
{
	int	chars_printed;

	chars_printed = 0;
	if (!n)
		return (n);
	chars_printed += ft_print_hex_process(n / 16, c);
	if (n % 16 > 9)
	{
		if (*c == 'X')
			chars_printed += ft_print_char(n % 16 + 'A' - 10);
		else
			chars_printed += ft_print_char(n % 16 + 'a' - 10);
	}
	else
		chars_printed += ft_print_char(n % 16 + '0');
	return (chars_printed);
}

int	ft_print_hex(unsigned int n, const char *c)
{
	int	chars_printed;

	chars_printed = 0;
	if (n == 0)
		chars_printed += ft_print_char('0');
	else
		chars_printed += ft_print_hex_process(n, c);
	return (chars_printed);
}
