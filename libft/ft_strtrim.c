/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:10:30 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/01 08:17:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_index(const char *str, const char *set)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (ft_strchr(set, str[counter]) == NULL)
			break ;
		counter++;
	}
	return (counter);
}

static int	end_index(const char *str, const char *set, int str_len)
{
	while (str_len > 0)
	{
		if (ft_strchr(set, str[str_len]) == NULL)
			break ;
		str_len--;
	}
	return (str_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char				*result;
	unsigned int		start;
	unsigned int		end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = start_index(s1, set);
	end = end_index(s1, set, ft_strlen(s1));
	result = ft_substr(s1, start, (end + 1 - start));
	return (result);
}
