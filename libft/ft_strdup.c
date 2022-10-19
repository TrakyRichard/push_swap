/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:24:00 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/09 05:43:29 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*copy;

	size = ft_strlen(s1) + 1;
	copy = (char *) malloc(size * sizeof(*s1));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s1, size);
	return (copy);
}
