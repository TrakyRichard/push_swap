/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 03:01:21 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/01 08:26:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct ft_printf
{
	va_list	args;
	int		chars_printed;
}	t_ft_printf;

int			ft_printf(const char *format, ...);
int			ft_printf_arg(const char c, t_ft_printf *t_printf);
int			ft_print_char(char c);
int			ft_print_str(char *str);
int			ft_print_num(int n);
int			ft_print_uns(unsigned int n);
int			ft_print_hex(unsigned int n, const char *c);
int			ft_print_adrr(unsigned long int n);
int			is_char(const int *c);
int			is_num(const int *c);
int			is_adrr(const int *c);
int			is_hex(const int *c);
int			is_str(const int *c);
int			is_uns(const int *c);
int			is_percent(const int *c);

#endif
