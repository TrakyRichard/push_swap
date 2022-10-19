/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:17:39 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/09 19:22:05 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	s_len;
	size_t	size;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < len)
		size = s_len + 1;
	else
		size = len + 1;
	p = malloc(size * sizeof(*s));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (((i + start) < (len + start)) && s[i + start] != '\0')
	{
		if (start >= s_len)
			break ;
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}
