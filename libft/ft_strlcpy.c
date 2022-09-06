/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 05:00:15 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/08 22:57:28 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;
	size_t	len;

	ret = ft_strlen(src);
	if (dstsize)
	{
		if ((ret >= dstsize))
			len = dstsize - 1;
		else
			len = ret;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (ret);
}
