/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 04:35:51 by rkanmado          #+#    #+#             */
/*   Updated: 2022/10/15 07:24:54 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

void	print_err_mess(void)
{
	ft_error("KO");
	return ;
}

void	print_suc_mess(void)
{
	ft_error("OK");
	return ;
}

int	ft_strnumcmp(const char *s1, const char *s2, size_t n)
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

void	can_terminate(t_push_swap *ps)
{
	if (ps->stack_b.size == 0 && ft_is_rev_sorted(&ps->stack_a.head))
		print_suc_mess();
	print_err_mess();
	return ;
}
