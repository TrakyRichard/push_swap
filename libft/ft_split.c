/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:46:35 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/11 07:10:29 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct split_interface
{
	char		**results;
	size_t		next;
	size_t		prev;
	int			can_add;
	int			counter;
}	t_split_interface;

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

static int	found_next(const char *s, int c)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == c && c != '\0')
			return (i);
		i++;
	}
	return (i);
}

static char	**free_splits(char **splits, size_t count)
{
	while (count)
	{
		free(splits[count]);
		count--;
	}
	free(splits);
	return (NULL);
}

static t_split_interface	split_process(t_split_interface split, \
		char const *s, char c, size_t slen)
{
	split.next = 0;
	split.prev = 0;
	split.counter = 0;
	split.can_add = 0;
	while (split.prev < slen && s[split.prev] != '\0')
	{
		if (s[split.prev] != c && split.can_add == 0)
		{
			split.next = found_next(&s[split.prev], c);
			split.results[split.counter] = ft_substr(s, split.prev, split.next);
			if (split.results[split.counter] == NULL)
			{
				split.results = free_splits(split.results, split.counter + 1);
				return (split);
			}
			split.prev += split.next;
			split.counter++;
			split.can_add = 1;
		}
		if (s[split.prev] == c)
			split.can_add = 0;
		split.prev++;
	}
	split.results[split.counter] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	t_split_interface	split;

	if (s == NULL)
		return (NULL);
	split.results = (char **) malloc((ft_word_count(s, c) + 1) \
			* sizeof(char *));
	if (split.results == NULL)
		return (NULL);
	split = split_process(split, s, c, ft_strlen(s));
	return (split.results);
}
