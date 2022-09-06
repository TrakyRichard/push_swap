/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 05:04:47 by rkanmado          #+#    #+#             */
/*   Updated: 2022/06/28 01:23:00 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					counter;
	const unsigned char		*p1 = s1;
	const unsigned char		*p2 = s2;

	counter = 0;
	while (counter < n)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		counter++;
	}
	return (0);
}
