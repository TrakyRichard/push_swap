/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adrr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:26:28 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/23 06:43:01 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_adrr_process(unsigned long int n)
{
	int	chars_printed;

	chars_printed = 0;
	if (n == 0)
		return (chars_printed);
	chars_printed += ft_print_adrr_process(n / 16);
	if (n % 16 > 9)
		chars_printed += ft_print_char(n % 16 + 'a' - 10);
	else
		chars_printed += ft_print_char(n % 16 + '0');
	return (chars_printed);
}

int	ft_print_adrr(unsigned long int n)
{
	int	chars_printed;

	chars_printed = 0;
	chars_printed += ft_print_str("0x");
	if (n == 0)
		chars_printed += ft_print_char('0');
	else
		chars_printed += ft_print_adrr_process(n);
	return (chars_printed);
}
