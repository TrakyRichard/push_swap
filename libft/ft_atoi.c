/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 07:49:50 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/11 05:51:35 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_overflow_before(long n, int sign)
{
	if (n < -2147483648 || n > 2147483647)
	{
		if (sign > 0)
			return (-1);
		if (sign < 0)
			return (0);
	}
	return ((int) n);
}

static int	my_atoi(const char *str, int i, int sign)
{
	long		num;

	num = 0;
	while (str[i] >= 48 && str[i] <= 57)
		num = 10 * num + (str[i++] - '0');
	return (ft_check_overflow_before(num * sign, sign));
}

int	ft_atoi(const char *str)
{
	int				sign;
	int				i;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (my_atoi(str, i, sign));
}
