/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:09:50 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/10 23:15:13 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct itoa_interface
{
	char	*str;
	int		sign;
	int		counter;
}	t_itoa_interface;

static int	number_of_digit(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

static void	decrement_counter(char *c, int *counter, int n)
{
	*c = n;
	(*counter)--;
}

char	*ft_itoa(int n)
{
	t_itoa_interface	itoa;
	long int			num;

	num = n;
	itoa.counter = number_of_digit(num);
	itoa.str = (char *) malloc(sizeof(char) * (itoa.counter + 1));
	if (itoa.str == NULL)
		return (NULL);
	itoa.str[itoa.counter--] = '\0';
	if (n < 0)
	{
		itoa.str[0] = '-';
		num *= -1;
	}
	else
		itoa.str[0] = '0';
	while (num)
	{
		decrement_counter(&itoa.str[itoa.counter], &itoa.counter, \
			(num % 10) + '0');
		num = num / 10;
	}
	return (itoa.str);
}
