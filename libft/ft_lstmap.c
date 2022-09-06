/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:49:45 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/09 17:12:43 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*first_element;

	if (!lst || !*f)
		return (NULL);
	first_element = ft_lstnew((*f)(lst->content));
	if (first_element == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		new_list = ft_lstnew((*f)(lst->content));
		if (!new_list)
		{
			ft_lstclear(&first_element, del);
			return (NULL);
		}
		ft_lstadd_back(&first_element, new_list);
	}
	return (first_element);
}
