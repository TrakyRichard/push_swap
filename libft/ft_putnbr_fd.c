/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 05:31:25 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/11 00:40:33 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fd_modulo(int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (-1);
	}
	return (1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	sign = fd_modulo(&n);
	if (sign < 1)
		ft_putchar_fd('-', fd);
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n % 10 + '0', fd);
	return ;
}
