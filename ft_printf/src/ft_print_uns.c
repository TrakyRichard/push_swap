/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:51:49 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/23 04:09:16 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_uns_process(unsigned int n)
{
	int	chars_printed;

	chars_printed = 0;
	if (!n)
		return (chars_printed);
	chars_printed += ft_print_uns_process(n / 10);
	chars_printed += ft_print_char(n % 10 + '0');
	return (chars_printed);
}

int	ft_print_uns(unsigned int n)
{
	int	chars_printed;

	chars_printed = 0;
	if (n == 0)
		chars_printed += ft_print_char('0');
	else
		chars_printed += ft_print_uns_process(n);
	return (chars_printed);
}
