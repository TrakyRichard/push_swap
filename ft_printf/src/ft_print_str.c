/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:38:16 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/23 06:22:51 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_str(char *str)
{
	int	chars_printed;

	chars_printed = 0;
	if (str == NULL)
	{
		chars_printed += ft_print_str("(null)");
		return (chars_printed);
	}
	while (*str != '\0')
	{
		chars_printed += ft_print_char(*str);
		str++;
	}
	return (chars_printed);
}
