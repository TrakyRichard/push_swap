/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:25:50 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/01 08:16:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t					counter;
	const unsigned char		*p1 = (const unsigned char*)s1;
	const unsigned char		*p2 = (const unsigned char*)s2;

	counter = 0;
	while (counter < n && (*p1 != '\0' || *p2 != '\0'))
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		counter++;
		p1++;
		p2++;
	}
	return (0);
}
