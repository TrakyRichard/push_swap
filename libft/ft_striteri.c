/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 04:02:27 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/03 00:18:59 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		counter;

	if (s == NULL || f == NULL)
		return ;
	counter = 0;
	while (s[counter] != '\0')
	{
		f(counter, &s[counter]);
		counter++;
	}
	return ;
}
