/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:12:28 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/08 21:43:53 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		counter;
	int		len;

	counter = 0;
	len = ft_strlen(s);
	while (counter <= len)
	{
		if (s[counter] == (unsigned char)c)
			return ((char *)(&s[counter]));
		counter++;
	}
	return (NULL);
}
