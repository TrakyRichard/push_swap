/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 04:16:28 by rkanmado          #+#    #+#             */
/*   Updated: 2022/06/27 22:15:34 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}
